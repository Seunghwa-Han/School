import sys 
input = sys.stdin.readline 

N = int(input()) # 3 ≤ N ≤ 999
num = int(input())
n_square = N**2 

ans = [[0]*N for _ in range(N)]
ans_coor = None 

for i in range(N):
	ans[i][0] = n_square-i
	if ans[i][0]==num:
		ans_coor = [i+1, 1]

i = N-2
j = 0 
for l in range(N, 1, -1): # [N, 2]
	if l %2 == 1:
		i += 1
		for k in range(j, j+l-1):
			ans[i][k+1] = ans[i][k]-1
			if ans[i][k+1]==num:
				ans_coor = [i+1, k+2]
		j = k+1
		for i in range(i, i-l+1, -1):
			ans[i-1][j] = ans[i][j]-1
			if ans[i-1][j]==num:
				ans_coor = [i, j+1]
	else:
		i -= 1
		for k in range(j, j-l+1, -1):
			ans[i][k-1] = ans[i][k]-1
			if ans[i][k-1]==num:
				ans_coor = [i+1, k]
		j = k-1
		for i in range(i, i+l-1):
			ans[i+1][j]=ans[i][j]-1 
			if ans[i+1][j]==num:
				ans_coor = [i+2, j+1]

for line in ans:
	print(*line)
print(*ans_coor)


	
'''
N = 7
49 26 27 28 29 30 31
48 25 10 11 12 13 32
47 24  9  2  3 14 33
46 23  8  1  4 15 34
45 22  7  6  5 16 35
44 21 20 19 18 17 36
43 42 41 40 39 38 37
'''