import sys 
input = sys.stdin.readline 

N = int(input()) # 1 ≤ N < 15

ans = 0
y_visit = [False]*N
sum_visit = [False]*2*N
sub_visit = [False]*2*N

def dfs(x, depth):
    global ans 
    if depth == N:
        ans += 1
        return
    
    i = x+1 
    for j in range(N):
        tmp = i-j+N-1
        if not y_visit[j] and not sum_visit[i+j] and not sub_visit[tmp]:
            y_visit[j]=True 
            sum_visit[i+j]=True
            sub_visit[tmp]=True 
            dfs(i,depth+1)
            y_visit[j]=False 
            sum_visit[i+j]=False
            sub_visit[tmp]=False 


dfs(-1,0)
print(ans)