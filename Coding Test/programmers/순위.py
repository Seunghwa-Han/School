def solution(n, results):
    answer = 0
    order = [0 for _ in range(n+1)]
    graphs = [[0]*(n+1) for _ in range(n+1)]
    for u, v in results:
        graphs[v][u] = 1
    
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graphs[i][k] and graphs[k][j] and not graphs[i][j]:
                        graphs[i][j]=1
    
    for i in range(1, n+1):
        cnt = graphs[i].count(1)
        for j in range(1, n+1):
            if graphs[j][i]:
                cnt+=1
        if cnt == n-1:
            answer += 1
    return answer