import sys 
input = sys.stdin.readline 

N = int(input())

dp = [0]*(N+1)
for i in range(2, N+1):
    min_val = i 
    if i %3 ==0:
        min_val = min(min_val, dp[i//3])
    if i%2 ==0:
        min_val = min(min_val, dp[i//2])
    min_val = min(min_val, dp[i-1])
    dp[i] = min_val + 1
print(dp[N])
