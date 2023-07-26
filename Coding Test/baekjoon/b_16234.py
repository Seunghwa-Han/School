import sys
sys.setrecursionlimit(10**6)
N, L, R = map(int, input().split()) # 1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100
A = [list(map(int, input().split())) for _ in range(N)]

move = [(1,0),(-1,0),(0,1),(0,-1)]

def func(i, j, coord):
	global sum_val 
	visit[i][j] = True 
	for di, dj in move:
		x = i+di 
		y = j+dj 
		if 0<=x<N and 0<=y<N and not visit[x][y]:
			if L<=abs(A[i][j]-A[x][y])<=R:
				coord.append((x,y))
				sum_val += A[x][y]
				func(x,y, coord)

flag = True 
ans = 0
while flag:
	visit = [[False]*N for _ in range(N)]
	flag = False 

	for i in range(N):
		for j in range(N):
			if not visit[i][j]:
				coord = [(i,j)]
				sum_val = A[i][j]
				func(i,j, coord)
				if len(coord)>=2:
					flag = True 
					sum_val = int(sum_val/len(coord))
					for x, y in coord:
						A[x][y] = sum_val
	if flag: 
		ans += 1

print(ans)