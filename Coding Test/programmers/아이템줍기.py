'''
https://school.programmers.co.kr/questions/32456 방법 참고 
* 주의사항 
- 좌표와 list에서 x,y 축이 다름 
- 그냥 list에 표기할 경우 너비나 높이차이 1인 경우에 바로 윗부분에 표기되므로 연결되어있는거처럼 착각됨 
'''
import sys 
ans = sys.maxsize
MAX = 102
route = []
def solution(rectangle, characterX, characterY, itemX, itemY):
    global route
    route = [[0]*MAX for _ in range(MAX)]
    
    for x1,y1, x2,y2 in rectangle:
        for i in range(x1*2, x2*2+1):
            for j in range(y1*2, y2*2+1):
                route[j][i]=1
    for x1,y1, x2,y2 in rectangle:
        for i in range(x1*2+1, x2*2):
            for j in range(y1*2+1, y2*2):
                route[j][i]=0
    
    route[characterY*2][characterX*2]=0
    dfs((characterX*2, characterY*2), (itemX*2, itemY*2), 0)
    return ans//2

def dfs(coord, item, cnt):
    global ans
    if coord == item:
        ans = min(ans, cnt) 
        return 
    for dx,dy in ((-1,0),(1,0),(0,1),(0,-1)):
        nx, ny = coord[0]+dx, coord[1]+dy

        if route[ny][nx]==1:
            route[ny][nx]=0
            dfs((nx,ny), item, cnt+1)
            route[ny][nx]=1

'''
BFS 
'''
from collections import deque 
def solution(rectangle, characterX, characterY, itemX, itemY):
    route = [[0]*102 for _ in range(102)]
    
    for x1,y1, x2,y2 in rectangle:
        for i in range(x1*2, x2*2+1):
            for j in range(y1*2, y2*2+1):
                route[j][i]=1
    for x1,y1, x2,y2 in rectangle:
        for i in range(x1*2+1, x2*2):
            for j in range(y1*2+1, y2*2):
                route[j][i]=0
                
    q = deque()
    q.append((characterX*2, characterY*2, 0))
    while q:
        x,y,cnt = q.popleft()
        if (x,y)==(itemX*2,itemY*2):
            return cnt//2 
        
        for dx,dy in ((-1,0),(1,0),(0,1),(0,-1)):
            nx, ny = x+dx, y+dy
            if route[ny][nx]==1:
                route[ny][nx]=0
                q.append((nx,ny, cnt+1))
    
    return 1