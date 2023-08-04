import sys 
input = sys.stdin.readline 

N, M = map(int, input().split()) # 1 ≤ M ≤ N ≤ 8

nums = []
def dfs(start):
    if len(nums)==M:
        print(*nums)
        return 
    for i in range(start, N+1):
        nums.append(i)
        dfs(i)
        nums.pop()

dfs(1)