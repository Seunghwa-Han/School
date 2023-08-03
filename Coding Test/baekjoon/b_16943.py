import sys 
input = sys.stdin.readline
A, B = input().split()

ans = -1 
# method1 
# def func(num, nums):
# 	global ans 
# 	if len(num)==len(A):
# 		if int(num) <int(B):
# 			ans = max(ans, int(num))
# 		return 
# 	for n in nums:
# 		if not (num+n).startswith('0'):
# 			tmp = nums.copy()
# 			tmp.remove(n)
# 			func(num+n, tmp)
# func('', list(A))

# method2 
# from itertools import permutations 
# for p in permutations(list(A), len(A)):
# 	num = ''.join(p)
# 	if not num.startswith('0') and int(num) < int(B):
# 		ans = max(ans, int(num))

# method3 (dfs)
visited = [False]*len(A)
N = len(A)
def dfs(dep, num):
	global ans 
	if dep == N:
		if int(num) < int(B):
			ans = max(int(num), ans)
		return 
	for i in range(N):
		if not visited[i]:
			if (num+A[i])[0] != '0':
				visited[i] = True 
				dfs(dep+1, num+A[i])
				visited[i] = False 
dfs(0, '')
print(ans)
