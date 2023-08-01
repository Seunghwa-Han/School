import sys
input = sys.stdin.readline
N = int(input()) # 1≤N≤5,000
arr = list(map(int, input().split()))

dp = [[0]*N for _ in range(2)]

for i in reversed(range(N)):
	for j in range(i+1, N):
		row = i%2 
		if arr[i]==arr[j]:
			dp[row][j] = dp[row-1][j-1]
		else:
			dp[row][j] = min(dp[row][j-1], dp[row-1][j]) + 1

# dp = [[0]*N for _ in range(N)] 
# for length in range(1, N):
# 	for i in range(0, N-length):
# 		j = i+length 
# 		if arr[i]==arr[j]:
# 			dp[i][j] = dp[i+1][j-1]
# 		else:
# 			dp[i][j] = min(dp[i][j-1], dp[i+1][j])+1

# dp = [[0]*(N-i) for i in range(N)]
# for i in range(N-1):
# 	if arr[i]!=arr[i+1]:
# 		dp[i][1] = 1
# for length in range(2, N):
# 	for i in range(0, N-length):
# 		j = length
# 		if arr[i]==arr[i+length]:
# 			dp[i][j] = dp[i+1][j-1-1]
# 		else:
# 			dp[i][j] = min(dp[i][j-1], dp[i+1][j-1])+1

print(dp[0][N-1])