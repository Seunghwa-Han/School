import sys 
input = sys.stdin.readline 

N = int(input()) # 4 ≤ N ≤ 20, N은 짝수
S = [list(map(int, input().split())) for _ in range(N)]

# S[i][j]랑 S[j][i] 합해서 S[i][j]에 저장해놓기 
for length in range(1, N):
    for i in range(N-length):
        S[i][i+length] = S[i][i+length]+S[i+length][i]

# [0,N)까지 N//2개 고른 조합 
# combinations 사용해서 나온 결과 리스트 (res)의 앞,뒤 대칭으로 start, link 팀이 구성됨 
from itertools import combinations
res = list(combinations([i for i in range(N)], N//2))
res_len = len(res)
ans = 100
for i in range(res_len//2):
    j = res_len-1-i 
    start = list(combinations(res[i], 2))
    start_val = 0
    for x,y in start:
        start_val += S[x][y]
    link = list(combinations(res[j],2))
    link_val = 0
    for x,y in link:
        link_val += S[x][y]
    ans = min(ans, abs(start_val-link_val))
print(ans)