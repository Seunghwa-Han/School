import sys 
input = sys.stdin.readline 

N, M = map(int, input().split()) # 1 ≤ M ≤ N ≤ 8

num = []
def dfs():
	if len(num)==M:
		print(*num)
		return 
	for i in range(1, N+1):
		if len(num)==0 or len(num)>0 and i>num[-1]:
			num.append(i)
			dfs()
			num.pop()
dfs()