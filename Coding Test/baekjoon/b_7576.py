import sys 
from collections import deque 
input = sys.stdin.readline 

M, N = map(int, input().split()) # 2 ≤ M,N ≤ 1,000
box = [list(map(int, input().split())) for _ in range(N)]
max_value = -1
visited = [[False]*M for _ in range(N)]

def bfs(q):
	global max_value 
	while q:
		x,y,depth = q.popleft()
		max_value = max(max_value, depth)
		
		for dx,dy in ((1,0), (-1,0), (0,1),(0,-1)):
			nx = x+dx 
			ny = y+dy 
			if 0<=nx<N and 0<=ny<M and not visited[nx][ny] and box[nx][ny]==0:
				visited[nx][ny]=0
				box[nx][ny]=1
				q.append((nx,ny, depth+1))

q = deque()
for i in range(N):
	for j in range(M):
		if not visited[i][j] and box[i][j]==1:
			q.append((i,j,0))
bfs(q)

for i in range(N):
	for j in range(M):
		if box[i][j]==0:
			max_value = -1
			break 
print(max_value)