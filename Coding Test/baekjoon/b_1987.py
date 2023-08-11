import sys 
input = sys.stdin.readline 

R,C = map(int, input().split())
board = [list(map(lambda x: ord(x)-65, input().rstrip())) for _ in range(R)]

ans = 0 
path = [False]*26

def dfs(i,j, cnt):
    global ans 
    ans = max(ans, cnt)

    for dx, dy in ((0,1),(0,-1),(1,0),(-1,0)):
        nx = dx+i 
        ny = dy+j 
        if 0<=nx<R and 0<=ny<C and not path[board[nx][ny]]:
            path[board[nx][ny]]=True 
            dfs(nx, ny, cnt+1)
            path[board[nx][ny]]=False 

path[board[0][0]]=True 
dfs(0,0, 1)
print(ans)

'''
import sys 
from collections import deque

input=sys.stdin.readline
R,C = map(int, input().split())
board=[list(input()) for _ in range(R)] 

ans=1
def bfs(x,y):
    global ans
    q=set([(x,y,board[x][y])])
    while q:
        x,y,path=q.pop()
        for dx,dy in ((0,1),(0,-1),(1,0),(-1,0)):
            nx=x+dx
            ny=y+dy
            if 0<=nx<R and 0<=ny<C and board[nx][ny] not in path:
                q.add((nx,ny,path+board[nx][ny]))
                ans=max(ans,len(path)+1)
                
bfs(0,0)
print(ans)
'''