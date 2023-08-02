import sys 
input = sys.stdin.readline 
N = int(input()) # 1 ≤ N ≤ 500
matrix = [list(map(int, input().split())) for _ in range(N)] # 1 ≤ r, c ≤ 500

dp = [[0]*N for _ in range(N)]
max_val = 2**(31) -1 
for l in range(1, N):
	for i in range(N-l):
		j = i+l 
		dp[i][j] = max_val 
		for k in range(i, j):
			dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+matrix[i][0]*matrix[k][1]*matrix[j][1])
print(dp[0][N-1])

# pypy3로만 통과 