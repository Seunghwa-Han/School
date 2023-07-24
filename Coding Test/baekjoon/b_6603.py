from itertools import combinations

def dfs(i, dep, k):
	out.append(line[i])

	if dep == 6:
		print(*out)
	else:
		for j in range(i+1, k):
			dfs(j, dep+1, k)
	
	out.pop()

def dfs2(idx, dep):
	if dep == 6:
		print(*out)
		return 
	
	for i in range(idx, k):
		out.append(S[i])
		dfs2(i+1, dep+1)
		out.pop()

while True:
	line = list(map(int, input().split()))
	k = line[0]
	if k == 0:
		break
	S = line[1:]
	# line.sort()
	# comb = combinations(line, 6)
	# for c in comb:
	# 	print(*c)

	# for i in range(k-6+1):
	# 	out = []
	# 	dfs(i, 1, k)
	out = []
	dfs2(0,0)

	print()

