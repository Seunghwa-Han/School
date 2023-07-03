import sys 
input = sys.stdin.readline
N, M = map(int, input().split())
num = [list(map(int, input().split())) for _ in range(N)]

ans = 0

visited = [[False for _ in range(M)] for _ in range(N)]
move = [(0,1), (0,-1), (-1,0),(1,0)]
def dfs(x, y, s, d):
    global ans, visited
    
    s += num[x][y]
    visited[x][y] = True
    if d == 4:
        ans = max(ans, s)
        return 
    for dx, dy in move:
        if 0<=x+dx<N and 0<=y+dy<M and not visited[x+dx][y+dy]:
            dfs(x+dx, y+dy, s, d+1)
            visited[x+dx][y+dy] = False

move2 = [[(0,0), (0,1),(0,2),(1,1)], [(0,0), (0,1),(0,2),(-1,1)],
         [(0,0), (0,1),(-1,1),(1,1)], [(0,0), (1,0),(2,0),(1,1)]]

tetris=[[(0,0),(0,1),(0,2),(0,3)],\
        [(0,0),(1,0),(2,0),(3,0)],\
        [(0,0),(1,0),(0,1),(1,1)],\
        [(0,0),(1,0),(2,0),(2,1)],\
        [(0,1),(1,1),(2,1),(2,0)],\
        [(0,0),(0,1),(1,1),(2,1)],\
        [(0,0),(0,1),(1,0),(2,0)],\
        [(0,0),(1,0),(1,1),(1,2)],\
        [(0,2),(1,1),(1,2),(1,0)],\
        [(0,0),(0,1),(0,2),(1,2)],\
        [(0,0),(1,0),(0,1),(0,2)],\
        [(0,0),(1,0),(1,1),(2,1)],\
        [(0,1),(1,1),(1,0),(2,0)],\
        [(1,0),(1,1),(0,1),(0,2)],\
        [(0,0),(0,1),(1,1),(1,2)],\
        [(0,1),(1,0),(1,1),(1,2)],\
        [(0,0),(0,1),(0,2),(1,1)],\
        [(0,0),(1,0),(1,1),(2,0)],\
        [(0,1),(1,1),(1,0),(2,1)]]

# DFS 
for i in range(N):
    for j in range(M):
        dfs(i,j,0,1)
        visited[i][j] = False
        for k in move2:
            tmp = 0
            for x,y in k:
                if 0<=i+x<N and 0<=j+y<M:
                    tmp += num[i+x][j+y]
                else:
                    tmp = 0
                    break
            ans = max(tmp, ans)

# brute force 
# for i in range(N):
#     for j in range(M):
#         for k in tetris:
#             tmp = 0
#             for x,y in k:
#                 if 0<=i+x<N and 0<=j+y<M:
#                     tmp += num[i+x][j+y]
#                 else:
#                     tmp = 0
#                     break
#             ans = max(tmp, ans)

print(ans)