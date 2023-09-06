graph = None 
visit = None
def dfs(idx, wire):
    for u in graph[idx]:
        if not visit[u]:
            visit[u]=True
            wire = dfs(u, wire+1)
    return wire
    
def do_dfs(n):
    global visit
    visit = [False]*n
    wire = []
    for i in range(n):
        if not visit[i]:
            visit[i]=True 
            wire.append(dfs(i, 1))
    return wire

def solution(n, wires):
    global graph
    answer = n
    graph = [[] for _ in range(n)]
    for u,v in wires:
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    
    for u,v in wires:
        graph[u-1].remove(v-1)
        graph[v-1].remove(u-1)
        wire = do_dfs(n)
        if len(wire)==2:
            answer = min(answer, abs(wire[1]-wire[0]))
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
        
    return answer