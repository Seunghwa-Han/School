n = int(input())
A = list(map(int, input().split()))

dp = [0]*n 

for i in range(n):
	for j in range(i):
		if A[j]<A[i]:
			dp[i] = max(dp[i], dp[j]+1)
	if dp[i]==0:
		dp[i] = 1

print(max(dp))
'''
A =  10 20 10 30 20 50

f(1) = {50}
f(2)


A = 10 20 30 40 50 1 2 3 4 1 5 6 7 8

f(1) = {10}
f(5) = {10,20,30,40,50}

f(1) = 1
f(2) = 2
f(3) = 3

'''