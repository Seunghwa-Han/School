N = int(input()) # 1 ≤ N ≤ 1,000
maze = list(map(int, input().split())) # 0 ≤ Ai ≤ 100
dp = [1001 for _ in range(N)]
dp[N-1] = 0

for i in range(N-1, -1, -1):

	for di in range(1, maze[i]+1):
		if 0<=i+di<N:
			if dp[i+di] == -1:
				continue
			else:
				dp[i] = min(dp[i], dp[i+di]+1)
	if dp[i] == 1001:
		dp[i] = -1

print(dp[0])

'''
10
1 2  0 1 3 2 1 5 4 2
5 4 -1 3 2 2 2 1 1 0

'''