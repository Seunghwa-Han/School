from collections import deque
N, M, V = map(int, input().split())

arr = [tuple(map(int, input().split())) for _ in range(M)]

adj = [[] for i in range(N+1)]
for u, v in arr:
    adj[u].append(v)
    adj[v].append(u)

[adj[i].sort() for i in range(N+1)]

visit = [0 for _ in range(N+1)]
dfs_set = []
def dfs(idx):
    global visit, dfs_set
    visit[idx]=1
    dfs_set.append(idx)

    for u in adj[idx]:
        if visit[u] == 0:
            dfs(u)
dfs(V)
print(*dfs_set)

def bfs():
    visit = [0 for i in range(N+1)]
    dq = deque()
    dq.append(V)
    visit[V] = 1
    bfs_set = []

    while dq:
        v = dq.popleft()
        bfs_set.append(v)
        
        for u in adj[v]:
            if visit[u] == 0:
                visit[u]=1
                dq.append(u)
    return bfs_set
print(*bfs())