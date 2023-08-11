import sys 
from collections import deque 
input = sys.stdin.readline 

N = int(input())
A = [list(map(int, input().rstrip())) for _ in range(N)]

total = 0 
nums = []

def bfs(i, j):
    q = deque([(i,j)])
    cnt = 1
    A[i][j]=0
    while q:
        x, y = q.popleft()

        for dx,dy in ((-1,0),(1,0),(0,1),(0,-1)):
            nx = dx+x 
            ny = dy+y 
            if 0<=nx<N and 0<=ny<N and A[nx][ny]==1:
                cnt += 1
                A[nx][ny]=0
                q.append((nx,ny))
    nums.append(cnt)

def dfs(i,j):
    global cnt 
    A[i][j] = 0
    cnt += 1
    for dx,dy in ((-1,0),(1,0),(0,1),(0,-1)):
        nx = dx+i
        ny = dy+j 
        if 0<=nx<N and 0<=ny<N and A[nx][ny]==1:
            dfs(nx,ny)
    return cnt 

for i in range(N):
    for j in range(N):
        if A[i][j]==1:
            total += 1 
            # bfs(i,j)
            cnt =0
            dfs(i,j)
            nums.append(cnt)

print(total)
nums.sort()
for num in nums:
    print(num)