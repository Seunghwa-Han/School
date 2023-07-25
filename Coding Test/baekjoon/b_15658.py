N = int(input()) # 2 ≤ N ≤ 11
A = list(map(int, input().split()))
op = list(map(int, input().split())) # 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

dic = {0: '+', 1: '-', 2: '*', 3: '/'}
max_v = -1000000000
min_v = 1000000000
def dfs(idx, value): 
	global max_v, min_v
	if idx == N:
		max_v = max(max_v, value)
		min_v = min(min_v, value)
		return 

	for i in range(4):
		if op[i]>0:
			n_value = int(eval(str(value)+dic[i]+str(A[idx])))
			op[i] -= 1
			dfs(idx+1, n_value)
			op[i] += 1

dfs(1, A[0])
print(max_v)
print(min_v)