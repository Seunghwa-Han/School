N = int(input()) # 1 ≤ N ≤ 20
S = list(map(int, input().split()))

# def dfs(idx, dep, sum_):
# 	if dep == length:
# 		out.add(sum_)
# 		return 

# 	for i in range(idx, N):
# 		sum_ += S[i]
# 		dfs(i+1, dep+1, sum_)
# 		sum_ -= S[i]

# out = set()
# for length in range(1, N+1):
# 	dfs(0,0,0)

out = set()
def dfs2(idx, sum_):
	if idx == N:
		return 
	sum_ += S[idx]
	out.add(sum_)
	dfs2(idx+1, sum_)
	sum_ -= S[idx]
	dfs2(idx+1, sum_)
dfs2(0,0)

res = set()
for i in range(1, max(out)+2):
	res.add(i)
res -= out 
print(min(res))