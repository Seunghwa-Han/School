def solution(n, computers):
    ans = 0
    
    adj = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i!=j and computers[i][j]:
                adj[i].append(j)
    
    visit = [False]*n 
    
    for i in range(n):
        if not visit[i]:
            dfs(i, visit, adj)
            ans += 1
    return ans

def dfs(n, visit, adj):
    visit[n]=True 
    
    for i in adj[n]:
        if not visit[i]:
            dfs(i, visit, adj)

'''
connected component 개수 찾는 문제 
'''

from collections import deque
def solution(n, computers):
    ans = 0
    
    adj = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i!=j and computers[i][j]:
                adj[i].append(j)
    
    visit = [False]*n 
    q = deque()
    
    for i in range(n):
        if not visit[i]:
            bfs(i, q, visit, adj)
            ans += 1
    
    return ans

def bfs(n, q, visit, adj):
    q.append(n)
    visit[n] = True

    while q:
        n = q.popleft()
    
        for i in adj[n]:
            if not visit[i]:
                visit[i]=True 
                q.append(i)