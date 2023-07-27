import sys
input = sys.stdin.readline
R, C, T = map(int, input().split()) # 6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000
A = [list(map(int, input().split())) for _ in range(R)]

move = ((1,0), (-1,0), (0,1),(0,-1))
air = [i for i in range(R) if A[i][0]==-1]

def spreadDust():
	# 먼지 확산 
	B = [[0]*C for _ in range(R)]
	for i in range(R):
		for j in range(C):
			if A[i][j] >= 5:
				dust = A[i][j]//5
				for di, dj in move:
					x, y = i+di, j+dj
					if 0<=x<R and 0<=y<C and A[x][y]!=-1:
						B[x][y] += dust
						B[i][j] -= dust
	for i in range(R):
		for j in range(C):
			A[i][j] += B[i][j]

for _ in range(T):
	spreadDust()
	# 공기 청정 
	x = air[0]
	for i in range(x-2, -1, -1): # x-1 ~ 0
		A[i+1][0]=A[i][0]
	for i in range(1, C): # 1 ~ C-1
		A[0][i-1] = A[0][i]
	for i in range(1, x+1): # 1 ~ x
		A[i-1][C-1] = A[i][C-1]
	for i in range(C-2, 0, -1): # C-2 ~ 1
		A[x][i+1] = A[x][i]
	A[x][1]=0
	x = air[1]
	for i in range(x+2, R):
		A[i-1][0]=A[i][0]
	for i in range(1,C):
		A[R-1][i-1] = A[R-1][i]
	for i in range(R-2, x-1,-1):
		A[i+1][C-1] = A[i][C-1]
	for i in range(C-2, 0, -1):
		A[x][i+1] = A[x][i]
	A[x][1]=0

ans = sum(map(sum, A))+2
print(ans)