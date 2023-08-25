import heapq
def solution(n, edge):
    answer = 0
    d = [50000 for _ in range(n+1)]
    d[0] = d[1] = 0
    
    graphs = [[] for _ in range(n+1)]
    for u,v in edge:
        graphs[u].append(v)
        graphs[v].append(u)
    
    q = []
    heapq.heappush(q, (0, 1))
    while q:
        dis, num = heapq.heappop(q)
        
        if d[num] < dis:
            continue 
            
        for u in graphs[num]:
            if dis+1<d[u]:
                d[u] = dis+1
                heapq.heappush(q, (d[u], u))

    answer = d.count(max(d))
    return answer