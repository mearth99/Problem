import os
from pathlib import Path
import git
from urllib import parse
import re
from dataclasses import dataclass
from typing import List, Optional

@dataclass
class Problem:
    level: str
    number: str
    name: str
    path: str
    categories: List[str]
    rank: int    # 난이도 순위
    platform: str  # 백준, SWEA, 프로그래머스
    
    def __lt__(self, other):
        # 먼저 출처별로 비교
        if self.platform != other.platform:
            return self.platform < other.platform
            
        # 같은 출처인 경우 rank로 비교
        if self.rank != other.rank:
            return self.rank < other.rank
            
        # rank가 같은 경우 문제 번호로 비교
        return int(self.number) < int(other.number)

def get_problem_rank(level: str) -> tuple[str, int]:
    """문제의 출처와 레벨 순위를 반환"""
    level_ranks = {
        '백준': {
            'Unrated': 6, 'Bronze': 5, 'Silver': 4, 'Gold': 3, 'Platinum': 2, 'Diamond': 1, 'Ruby': 0 
        },
        'SWEA': {
            'Unrated': 10, 'D0': 9, 'D1': 8, 'D2': 7, 'D3': 6, 'D4': 5, 'D5': 4, 'D6': 3, 'D7': 2, 'D8': 1, 'D9': 0,
        },
        '프로그래머스': {
            '0': 9, '1': 8, '2': 7, '3': 6, '4': 5, '5': 4, '6': 3, '7': 2, '8': 1, '9': 0,
        }
    }
    
    # SWEA D2 형식
    if level.startswith('D'):
        return ('SWEA', level_ranks['SWEA'].get(level, -1))
    
    # 프로그래머스 level 2 형식
    if level.lower().startswith('level'):
        level_num = level.split()[-1]
        return ('프로그래머스', level_ranks['프로그래머스'].get(level_num, -1))
    
    # 백준 Bronze II 형식
    for boj_level in ['Bronze', 'Silver', 'Gold', 'Platinum', 'Diamond', 'Ruby']:
        if boj_level in level:
            roman_values = {'I': 1, 'II': 2, 'III': 3, 'IV': 4, 'V': 5}
            tier = level.split()[-1]
            base_rank = level_ranks['백준'][boj_level]
            # 세부 등급을 역순으로 계산 (I가 가장 높음)
            sub_rank = (6 - roman_values.get(tier, 0)) * 0.1
            return ('백준', base_rank + sub_rank)
            
    return ('Unknown', 0)

def extract_problem_info(content: str, readme_path: str) -> Optional[Problem]:
    """README.md 파일에서 문제 정보를 추출"""
    # 제목 추출
    title_pattern = r'# \[(.*?)\] (.*?) - (\d+)'
    title_match = re.search(title_pattern, content)
    
    if not title_match:
        return None
        
    level, name, number = title_match.groups()
    
    # 분류 추출
    categories = []
    category_pattern = r'### 분류\s*\n\s*(.*?)\s*\n'
    category_match = re.search(category_pattern, content)
    
    if category_match:
        raw_categories = category_match.group(1).strip()
        categories = [cat.strip() for cat in raw_categories.split(',') if cat.strip()]
    
    # 출처와 랭크 계산
    platform, rank = get_problem_rank(level)
    
    return Problem(
        level=level,
        number=number,
        name=name,
        path=readme_path,
        categories=categories,
        rank=rank,
        platform=platform
    )

def create_select(categories):
    """카테고리 목록으로 요소 생성"""
    if not categories:
        return ""
    select = ""
    for category in categories:
        select += f"`{category}` "
    
    return select

def create_markdown_table(problems: List[Problem]) -> str:
    """문제 목록을 출처별로 나눠서 마크다운 테이블로 변환"""
    # 출처별로 문제 분류
    problems_by_platform = {
        '백준': [],
        'SWEA': [],
        '프로그래머스': []
    }
    
    # 정렬된 문제들을 출처별로 분류
    sorted_problems = sorted(problems)
    for problem in sorted_problems:
        if problem.platform in problems_by_platform:
            problems_by_platform[problem.platform].append(problem)
    
    # 전체 테이블 문자열 생성
    all_tables = [ f"# 💻 백준, 프로그래머스, SWEA 허브\n\n" ]
    # 각 출처별로 테이블 생성
    for platform, platform_problems in problems_by_platform.items():
        if not platform_problems:  # 해당 출처의 문제가 없으면 건너뛰기
            continue
        # 출처별 제목 추가
        table = f"## 📁 {platform}\n\n"
        
        # 테이블 헤더
        table += "| Level | 문제 번호 | 이름 | 링크 | 분류 |\n"
        table += "|--------|------------|------|------|--------|\n"
        
        # 각 문제를 테이블 행으로 변환
        for problem in platform_problems:
            github_link = f"[링크]({parse.quote(problem.path)})"
            categories = create_select(problem.categories) if problem.categories else ''
            #categories = ', '.join(problem.categories) if problem.categories else ''
            table += f"| {problem.level} | {problem.number} | {problem.name} | {github_link} | {categories} |\n"
        
        # 테이블 구분선 추가
        table += "\n"
        
        all_tables.append(table)
    
    # 모든 테이블을 하나의 문자열로 합치기
    return '\n'.join(all_tables)



def find_all_readmes() -> List[Problem]:
    """모든 README.md 파일을 찾아서 문제 정보를 추출"""
    problems = []
    
    for root, _, files in os.walk('.'):
        readme_file = next((f for f in files if f.lower() == 'readme.md'), None)
        
        if readme_file:
            readme_path = Path(root) / readme_file
            try:
                with open(readme_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    relative_path = str(readme_path).replace('.\\', '').replace('./', '')
                    
                    problem = extract_problem_info(content, relative_path)
                    if problem:
                        problems.append(problem)
            except Exception as e:
                print(f"Error reading {readme_path}: {e}")
    
    return problems

def main():
    # README 파일들을 찾아서 문제 정보 추출
    problems = find_all_readmes()
    
    # 마크다운 테이블 생성
    table = create_markdown_table(problems)
    
    # README.md 파일에 결과 저장
    try:
        with open("README.md", 'w', encoding='utf-8') as f:
            f.write(table)
    except Exception as e:
        print(f"Error writing to README.md: {e}")
    
    # 결과 출력
    print(table)

if __name__ == "__main__":
    main()