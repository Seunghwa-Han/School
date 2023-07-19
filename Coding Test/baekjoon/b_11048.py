import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split()) # 1 ≤ N, M ≤ 1,000
maze = [list(map(int, input().split())) for _ in range(N)]

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
1 2 3 4
0 0 0 5
9 8 7 6

'''
