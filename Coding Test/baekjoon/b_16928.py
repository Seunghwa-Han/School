import sys 
input = sys.stdin.readline
N, M = map(int, input().split())  # 1 ≤ N, M ≤ 15
# ladder = [list(map(int, input().split())) for _ in range(N)]
# snake = [list(map(int, input().split())) for _ in range(M)]

ladder = dict()
snake = dict()
for _ in range(N):
	x, y = map(int, input().split())
	ladder[x]=y 
for _ in range(M):
	u, v = map(int, input().split())
	snake[u]=v

from collections import deque 
dq = deque([1])
dep = [101]*101
dep[1] = 0

while dq:
	num = dq.popleft()

	if num in ladder:
		dq.append(ladder[num])
		dep[ladder[num]] = dep[num]
	elif num in snake:
		dq.append(snake[num])
		dep[snake[num]] = dep[num]
	else:
		for i in range(6,0,-1):
			if num+i<=100 and dep[num]+1<dep[num+i]:
				dq.append(num+i)
				dep[num+i] = dep[num]+1

	# flag = False 
	# for l in ladder:
	# 	if num == l[0]:
	# 		dq.append(l[1])
	# 		dep[l[1]] = dep[num]
	# 		flag = True 
	# 		break 
	# if not flag:
	# 	for s in snake:
	# 		if num == s[0]:
	# 			dq.append(s[1])
	# 			dep[s[1]] = dep[num]
	# 			flag = True 
	# 			break 
	# if not flag:
	# 	for i in range(6,0,-1):
	# 		if num+i<=100 and dep[num]+1<dep[num+i]:
	# 			dq.append(num+i)
	# 			dep[num+i] = dep[num]+1
print(dep[100])