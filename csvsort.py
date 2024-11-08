import csv
import re
from pathlib import Path

def extract_number(problem_text):
    """문제 번호에서 숫자만 추출"""
    match = re.search(r'(\d+)', problem_text)
    return int(match.group(1)) if match else 0

def sort_csv_by_problem_number(file_path):
    """CSV 파일을 문제 번호 기준으로 정렬"""
    # CSV 파일 읽기
    with open(file_path, 'r', encoding='utf-8', newline='') as f:
        reader = csv.reader(f)
        header = next(reader)  # 헤더 저장
        rows = list(reader)    # 모든 행 읽기
    
    # 문제 번호를 기준으로 정렬
    sorted_rows = sorted(rows, key=lambda row: extract_number(row[1]))
    
    # 정렬된 데이터를 파일에 쓰기
    with open(file_path, 'w', encoding='utf-8', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(header)  # 헤더 쓰기
        writer.writerows(sorted_rows)  # 정렬된 데이터 쓰기

def main():
    # 처리할 플랫폼 목록
    platforms = ['백준', '프로그래머스', 'SWEA']
    
    # 각 플랫폼의 CSV 파일 처리
    for platform in platforms:
        csv_path = f"{platform}.csv"
        if Path(csv_path).exists():
            print(f"{csv_path} 파일 정렬 중...")
            try:
                sort_csv_by_problem_number(csv_path)
                print(f"{csv_path} 파일 정렬 완료")
            except Exception as e:
                print(f"{csv_path} 파일 처리 중 오류 발생: {e}")
        else:
            print(f"{csv_path} 파일이 존재하지 않습니다.")

if __name__ == "__main__":
    main()