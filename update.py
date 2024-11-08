import os
from pathlib import Path
import git
import csv
from urllib import parse 
def get_changed_files():
    """Get list of files changed in the most recent push"""
    repo = git.Repo('.')
    # Get the latest commit
    latest_commit = repo.head.commit
    # Get the parent commit
    parent_commit = latest_commit.parents[0] if latest_commit.parents else None
    
    if parent_commit:
        # Get the difference between latest and parent commit
        diffs = parent_commit.diff(latest_commit)
        changed_files = [diff.b_path for diff in diffs if diff.b_path]
    else:
        # If this is the first commit, get all tracked files
        changed_files = [item.path for item in repo.index.entries]
    return changed_files

def find_readmes_in_changed_paths():
    """Find and read README.md files in changed directories"""
    changed_files = get_changed_files()
    readme_contents = {}
    
    # Get unique directories from changed files
    changed_dirs = set(os.path.dirname(file) for file in changed_files)
    
    for directory in changed_dirs:
        # Skip if directory is empty (files in root)
        if not directory:
            directory = '.'
            
        readme_path = Path(directory) / 'README.md'
        # Check both README.md and readme.md
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

def create_csv_from_readmes(readme_contents):
    """
    readme_contents에서 정보를 추출하여 플랫폼별 CSV 파일 생성
    마크다운 형식의 링크 포함
    """
    # 플랫폼별로 데이터를 분류할 딕셔너리
    platform_data = {
        '백준': [],
        '프로그래머스': [],
        'SWEA': []
    }
    
    for path, content in readme_contents.items():
        # Path를 문자열로 변환하고 구성요소로 분리
        path_parts = Path(path).parts
        
        # 플랫폼 확인 (첫 번째 디렉토리)
        platform = path_parts[0]
        
        if platform not in platform_data:
            continue
        
        # 모든 플랫폼이 동일한 구조를 가짐
        level = path_parts[1]      # Silver, Gold, 1,2,3,4 등
        problem = path_parts[2]    # 문제 번호와 제목
        github_link = "[링크]({})".format(parse.quote(path))
        platform_data[platform].append([level, problem, github_link])
    
    # CSV 파일 생성
    for platform, data in platform_data.items():
        if not data:  # 데이터가 없으면 건너뛰기
            continue
            
        csv_filename = f"{platform}.csv"
        
        # CSV 파일이 이미 존재하는 경우 기존 데이터 읽기
        existing_data = set()
        if os.path.exists(csv_filename):
            with open(csv_filename, 'r', encoding='utf-8', newline='') as f:
                reader = csv.reader(f)
                next(reader)  # 헤더 건너뛰기
                for row in reader:
                    existing_data.add(tuple(row))
        
        # 새로운 데이터 추가
        all_data = set([tuple(row) for row in data]).union(existing_data)
        
        # CSV 파일 작성
        with open(csv_filename, 'w', encoding='utf-8', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['Level', '문제 번호', '링크'])  # 헤더
            writer.writerows(sorted(all_data))  # 정렬된 데이터 쓰기
        
        print(f"{csv_filename} 파일이 생성되었습니다.")


def main():
    # Get all README contents
    readme_contents = find_readmes_in_changed_paths()
    create_csv_from_readmes(readme_contents)

if __name__ == "__main__":
    main()