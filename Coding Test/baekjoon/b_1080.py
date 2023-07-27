N, M = map(int, input().split())
A = [list(map(int, input())) for _ in range(N)]
B = [list(map(int, input())) for _ in range(N)]

cnt = 0
for i in range(N-2):
	for j in range(M-2):
		if A[i][j]^B[i][j]: # 다르면 
			cnt += 1
			for di in range(3):
				for dj in range(3):
					A[i+di][j+dj] = not A[i+di][j+dj]

if A==B:
	print(cnt)
else:
	print(-1)