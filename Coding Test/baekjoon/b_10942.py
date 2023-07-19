import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input()) # 1 ≤ N ≤ 2,000
num = list(map(int, input().split()))
M = int(input()) # 1 ≤ M ≤ 1,000,000
ques = [list(map(int, input().split())) for _ in range(M)]

dp = [[-1 for _ in range(N)] for _ in range(N)]

'''
top-down 시간 초과 

def func(i, j):
	if j-i <= 1:
		dp[i][j]=1 if num[i]==num[j] else 0
	else:
		x = i+1
		y = j-1
		if dp[x][y] == -1:
			func(x, y)
		if dp[x][y] == 1:
			dp[i][j]=1 if num[i]==num[j] else 0
		elif dp[x][y] == 0:
			dp[i][j] = 0
'''

dp = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
	dp[i][i] = 1 
	if i+1<N:
		dp[i][i+1] = 1 if num[i]==num[i+1] else 0

for length in range(2, N+1):
	for i in range(N-length):
		j = i+length
		if num[i]==num[j] and dp[i+1][j-1]:
			dp[i][j]=1

for S,E in ques:
	print(dp[S-1][E-1])