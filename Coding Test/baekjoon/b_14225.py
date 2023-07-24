N = int(input()) # 1 ≤ N ≤ 20
S = list(map(int, input().split()))

def dfs(idx, dep, sum_):
	if dep == length:
		out.add(sum_)
		return 
	
	for i in range(idx, N):
		sum_ += S[i]
		dfs(i+1, dep+1, sum_)
		sum_ -= S[i]

out = set()
for length in range(1, N+1):
	dfs(0,0,0)

res = set()
for i in range(1, max(out)+1):
	res.add(i)
res -= out 
if res:
	print(min(res))
else:
	print(max(out)+1)