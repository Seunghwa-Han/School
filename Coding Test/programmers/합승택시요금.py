def solution(n, s, a, b, fares):
    answer = 20000000
    d = [[20000000]*n for _ in range(n)]
    
    for i in range(n):
        d[i][i]=0
    for u,v,w in fares:
        d[u-1][v-1]=w 
        d[v-1][u-1]=w
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k]+d[k][j])
    
    for i in range(n):
        answer = min(answer, d[s-1][i]+d[i][a-1]+d[i][b-1])
    
    return answer