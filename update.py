import os
from pathlib import Path
import git
from urllib import parse
import re


def find_all_paths():
    """모든 하위 경로에서 README.md 파일을 찾아서 반환"""
    all_contents = {}
    
    # 현재 디렉토리를 기준으로 모든 하위 디렉토리 탐색
    for root, dirs, files in os.walk('.'):
        # README.md 또는 readme.md 파일 찾기
        readme_file = None
        for file in files:
            if file.lower() == 'readme.md':
                readme_file = file
                break
                
        if readme_file:
            readme_path = Path(root) / readme_file
            try:
                with open(readme_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    # 상대 경로로 저장 (./ 제거)
                    relative_path = str(readme_path).replace('.\\', '').replace('./', '')
                    all_contents[relative_path] = content
            except Exception as e:
                print(f"Error reading {readme_path}: {e}")
    
    return all_contents

def get_changed_files():
    """Get list of files changed in the most recent push"""
    repo = git.Repo('.')
    latest_commit = repo.head.commit
    parent_commit = latest_commit.parents[0] if latest_commit.parents else None
    
    if parent_commit:
        diffs = parent_commit.diff(latest_commit)
        changed_files = [diff.b_path for diff in diffs if diff.b_path]
    else:
        changed_files = [item.path for item in repo.index.entries]
    return changed_files

def extract_categories(content):
    """README.md 파일에서 분류 항목을 추출"""
    categories = []
    
    # ### 분류와 그 다음 줄의 내용을 찾음
    pattern = r'### 분류\s*\n\s*(.*?)\s*\n'
    match = re.search(pattern, content)
    
    if match:
        # 첫 번째 캡처 그룹에서 카테고리 추출
        raw_categories = match.group(1).strip()
        # 쉼표로 구분된 카테고리들을 분리하고 앞뒤 공백 제거
        categories = [cat.strip() for cat in raw_categories.split(',')]
        # 빈 문자열 제거
        categories = [cat for cat in categories if cat]
    
    return categories

def create_select(categories):
    """카테고리 목록으로 HTML select 요소 생성"""
    if not categories:
        return ""
    select = "<select> "
    for category in categories:
        select += f"<option>{category}</option>"
    select += " </select>"
    return select

def find_readmes_in_changed_paths():
    """Find and read README.md files in changed directories"""
    changed_files = get_changed_files()
    readme_contents = {}
    
    changed_dirs = set(os.path.dirname(file) for file in changed_files)
    
    for directory in changed_dirs:
        if not directory:
            directory = '.'
            
        readme_path = Path(directory) / 'README.md'
        if not readme_path.exists():
            readme_path = Path(directory) / 'readme.md'
            
        if readme_path.exists():
            try:
                with open(readme_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    readme_contents[str(readme_path)] = content
            except Exception as e:
                print(f"Error reading {readme_path}: {e}")
    
    return readme_contents

def get_level_rank(platform, level):
    """플랫폼별 난이도 순위를 반환"""
    level_ranks = {
        '백준': {
            'Unrated': 0,
            'Bronze': 1,
            'Silver': 2,
            'Gold': 3,
            'Platinum': 4,
            'Diamond': 5,
            'Ruby': 6
        },
        'SWEA': {
            'D0': 0,
            'D1': 1,
            'D2': 2,
            'D3': 3,
            'D4': 4,
            'D5': 5,
            'D6': 6,
            'D7': 6,
            'D8': 6,
            'D9': 6,
        },
        '프로그래머스': {
            '0': 0,
            '1': 1,
            '2': 2,
            '3': 3,
            '4': 4,
            '5': 5,
            '6': 6,
            '7': 7,
            '8': 8,
            '9': 9,
        }
    }
    return level_ranks.get(platform, {}).get(level, 999)

def get_problem_number(problem):
    """문제 번호를 추출하여 정수로 반환"""
    number = ''.join(filter(str.isdigit, problem.split('_')[0]))
    return int(number) if number else 999999

def custom_sort_key(platform):
    """플랫폼별 커스텀 정렬 키 생성"""
    def sort_key(item):
        level, problem, _ = item[:3]  # 카테고리 정보가 있을 수 있으므로 처음 3개만 사용
        return (get_level_rank(platform, level), get_problem_number(problem))
    return sort_key

def find_platform_in_path(path_parts):
    """경로에서 플랫폼 이름을 찾음"""
    platforms = {'백준', '프로그래머스', 'SWEA'}
    for part in path_parts:
        if part in platforms:
            return part
    return None

def extract_path_info(path, path_parts, platform_index):
    """플랫폼 위치를 기반으로 레벨, 문제, README 경로 추출"""
    try:
        # 플랫폼 다음 부분을 레벨로, 그 다음을 문제 번호로 가정
        level = path_parts[platform_index + 1] if platform_index + 1 < len(path_parts) else "Unknown"
        problem = path_parts[platform_index + 2] if platform_index + 2 < len(path_parts) else "Unknown"
        
        # README.md 파일이 있는 디렉토리 경로 생성
        readme_dir = str(Path(*path_parts[:platform_index + 3]))  # 플랫폼 + 레벨 + 문제 번호까지의 경로
        return level, problem, readme_dir
        
    except IndexError:
        return "Unknown", "Unknown", path

def create_markdown_from_readmes(readme_contents):
    """readme_contents에서 정보를 추출하여 플랫폼별 마크다운 파일 생성"""
    platform_data = {
        '백준': [],
        '프로그래머스': [],
        'SWEA': []
    }
    
    for path, content in readme_contents.items():
        path_parts = Path(path).parts
        
        # 경로에서 플랫폼 찾기
        platform = find_platform_in_path(path_parts)
        if not platform:
            continue
            
        # 플랫폼의 인덱스 찾기
        platform_index = path_parts.index(platform)
        
        # 레벨, 문제, README 경로 정보 추출
        level, problem, readme_dir = extract_path_info(path, path_parts, platform_index)
        
        # README.md 파일 경로 생성
        readme_path = f"{readme_dir}/README.md"
        github_link = f"[링크]({parse.quote(readme_path)})"
        
        # 백준 플랫폼인 경우에만 분류 정보 추출
        categories_select = ""
        if platform == "백준":
            categories = extract_categories(content)
            categories_select = create_select(categories)
        
        platform_data[platform].append([level, problem, github_link, categories_select])
    
    for platform, data in platform_data.items():
        if not data:
            continue
            
        md_filename = f"{platform}.md"
        
        existing_data = set()
        if os.path.exists(md_filename):
            try:
                with open(md_filename, 'r', encoding='utf-8') as f:
                    lines = f.readlines()
                    for line in lines[3:]:
                        if '|' in line:
                            parts = [part.strip() for part in line.split('|')]
                            if len(parts) >= 5:
                                existing_data.add((parts[1], parts[2], parts[3], parts[4]))
            except Exception as e:
                pass
        
        all_data = set([tuple(row) for row in data]).union(existing_data)
        sorted_data = sorted(all_data, key=custom_sort_key(platform))
        
        try:
            with open(md_filename, 'w', encoding='utf-8') as f:
                f.write(f"# {platform} 문제 풀이\n\n")
                f.write("| Level | 문제 번호 | 링크 | 분류 |\n")
                f.write("|-------|-----------|------|------|\n")
                
                for item in sorted_data:
                    level, problem, link = item[:3]
                    select = item[3] if len(item) > 3 else ""
                    f.write(f"| {level} | {problem} | {link} | {select} |\n")
            
            print(f"{md_filename} 파일이 생성되었습니다.")
        except Exception as e:
            pass

def main():
    #all_contents = find_all_paths()
    #create_markdown_from_readmes(all_contents)
    readme_contents = find_readmes_in_changed_paths()
    create_markdown_from_readmes(readme_contents)

if __name__ == "__main__":
    main()
