M, N = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(M)]

dp = [[-1 for _ in range(N)] for _ in range(M)]
dp[M-1][N-1] = 0
move = [(0,1), (0,-1), (1,0), (-1,0)]


def func(i, j):
	global dp, M, N
	
	sum = 0
	for dx, dy in move:
		x = i+dx 
		y = j+dy
		if 0<=x<M and 0<=y<N and A[i][j]>A[x][y]:
			if x==M-1 and y==N-1:
				sum += 1
			elif dp[x][y]== -1:
				func(x, y)
			sum += dp[x][y]
	dp[i][j] = sum 

func(0,0)
print(dp[0][0])