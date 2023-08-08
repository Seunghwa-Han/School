import sys 
from collections import deque 
input = sys.stdin.readline 

def bfs(field, M, N):
    visit = [[False]*M for _ in range(N)]
    ans = 0
    for i in range(N):
        for j in range(M):
            if field[i][j]==1 and not visit[i][j]:
                ans += 1
                q = deque([(i,j)])
                while q:
                    x, y = q.popleft()

                    for dx,dy in ((-1,0),(1,0),(0,1),(0,-1)):
                        nx = x+dx 
                        ny = y+dy 
                        if 0<=nx<N and 0<=ny<M and not visit[nx][ny] and field[nx][ny]==1:
                            visit[nx][ny]=1
                            q.append((nx,ny))
    return ans 


T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    field = [[0]*M for _ in range(N)]
    for _ in range(K):
        u,v = map(int, input().split())
        field[v][u]=1
    print(bfs(field, M, N))
