from collections import deque 

N, M = map(int, input().split())

maze = [list(map(int, input())) for _ in range(N)]

d = [(0,1), (0,-1), (1,0), (-1,0)]
dq = deque()
dq.append((0,0))

def bfs():
    while dq:
        x, y = dq.popleft()

        for dx, dy in d:
            if 0<=x+dx<N and 0<=y+dy<M:
                if maze[x+dx][y+dy] == 1:
                    maze[x+dx][y+dy] = maze[x][y]+1  # bfs depth 
                    dq.append((x+dx, y+dy))
bfs()
print(maze[N-1][M-1])

'''
4 6
101111
101010
101011
111011

'''