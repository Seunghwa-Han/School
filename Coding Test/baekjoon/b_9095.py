import sys 
input = sys.stdin.readline 

T = int(input())
nums =[int(input()) for _ in range(T)]
max_num = max(nums)
dp = [0]*(max_num+1) 
dp[1]=1 
dp[2]=2
dp[3]=4
for i in range(4, max_num+1):
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3]

for num in nums:
    print(dp[num])