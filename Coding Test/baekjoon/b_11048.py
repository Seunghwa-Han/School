import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split()) # 1 ≤ N, M ≤ 1,000
maze = [list(map(int, input().split())) for _ in range(N)]

dp = [[0 for _ in range(M+1)] for _ in range(N+1)]

for i in range(1, N+1):
	for j in range(1, M+1):
		dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + maze[i-1][j-1]

print(dp[N][M])

'''
top-down

dp = [[-1 for _ in range(M)] for _ in range(N)]
dp[0][0] = maze[0][0]

move = [(-1,0), (0,-1), (-1,-1)]

def func(i, j):
	if dp[i][j] != -1:
		return dp[i][j]
	for dx, dy in move:
		x = i+dx 
		y = j+dy 
		if 0<=x<N and 0<=y<M:
			dp[i][j] = max(func(x,y), dp[i][j])
	dp[i][j] += maze[i][j]
	return dp[i][j]

print(func(N-1, M-1))
'''
