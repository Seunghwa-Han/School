N, S = map(int, input().split())
num = list(map(int, input().split()))

ans = 0
def dfs(idx, sum):
    global ans 
    if idx >= N:
        return
    sum += num[idx]
    if sum == S:
        ans += 1 
    dfs(idx+1, sum)
    dfs(idx+1, sum-num[idx])
dfs(0, 0)
print(ans)