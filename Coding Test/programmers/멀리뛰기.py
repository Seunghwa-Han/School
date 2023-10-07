ans = 0
def solution(n):
    # dfs(0, n)
    global ans
    cnt = [0,n,0]
    while 1:
        
        max_c = max(cnt[1], cnt[2])
        min_c = min(cnt[1], cnt[2])
        f = 1
        for i in range(cnt[1]+cnt[2], max_c, -1):
            f *= i 
        for i in range(1, min_c+1):
            f //= i 
        ans += f
        cnt[1]-=2
        cnt[2]+=1
        
        if cnt[1]<0: break 
    
    return ans%1234567

def dfs(sum_val, n):
    global ans
    if sum_val ==n:
        ans += 1
        return 
        
    if sum_val+2<=n:
        dfs(sum_val+2, n)
    if sum_val+1<=n:
        dfs(sum_val+1, n)

'''
처음에 dfs로 풀려고 했는데 몇개 빼고 runtime error랑 실패가 떠서 안됐음 

factorial 사용하려 했는데도 그랬음 
그래서 for문으로 factorial 구했는데도 그랬음 
-> /을 //로 바꾸니까 통과. 오버플로우 난듯 .. 

'''