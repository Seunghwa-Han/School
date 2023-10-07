from collections import deque
def solution(maps):
    n = len(maps)
    m = len(maps[0])
    q = deque()
    visit = [[False]*m for _ in range(n)]
    q.append((0,0,1))
    visit[0][0]=True 
    
    while q:
        x,y,cnt = q.popleft()
        
        if x==n-1 and y==m-1:
            return cnt
        
        for dx,dy in ((1,0),(-1,0),(0,1),(0,-1)):
            nx ,ny = x+dx, y+dy 
            if 0<=nx<n and 0<=ny<m and maps[nx][ny] and not visit[nx][ny]:
                visit[nx][ny] = True 
                q.append((nx,ny,cnt+1))

    return -1

'''
weight가 1인 상태에서 최단거리를 구하는거니까 bfs로 풀었다 

- 방문 배열을 사용하지 않는 방법 
visit을 True로 업데이트 하는 대신에, maps[nx][ny] = cnt +1 로 업데이트를 해줌 
line18의 조건을 maps[nx][ny]==1 일때로 바꿔줌 

'''