from collections import deque 

N, M = map(int, input().split())
maze = [list(map(int, input())) for _ in range(N)]

d = [(0,1), (0,-1), (1,0), (-1,0)]
visited = [[[0]*2 for _ in range(M)] for _ in range(N)]

dq = deque()
dq.append((0,0,0))
visited[0][0][0] = 1

def bfs():
    while dq:
        x, y, wall = dq.popleft()
        if x == N-1 and y == M-1:
            return visited[x][y][wall]
        for dx, dy in d:
            if 0<=dx+x<N and 0<=dy+y<M and visited[dx+x][dy+y][wall]==0:
                if maze[dx+x][dy+y] == 0:
                    visited[dx+x][dy+y][wall] = visited[x][y][wall]+1
                    dq.append((dx+x, dy+y, wall))
                if maze[dx+x][dy+y] == 1 and wall==0:
                    visited[dx+x][dy+y][1] = visited[x][y][wall]+1
                    dq.append((dx+x, dy+y, 1))
    return -1

print(bfs())

'''
6 4
0100
1110
1000
0000
0111
0000

'''