cnt = [0,0]
def solution(arr):
    dfs(arr, 0, 0, len(arr))
    return cnt

def dfs(arr, si, sj, l):
    s = arr[si][sj]
    flag = True 
    for i in range(si, si+l):
        for j in range(sj, sj+l):
            if s != arr[i][j]:
                flag = False 
                break 
    if flag: 
        cnt[s]+= 1
    elif l>1:
        dfs(arr, si, sj, l//2)
        dfs(arr, si+l//2, sj, l//2)
        dfs(arr, si, sj+l//2, l//2)
        dfs(arr, si+l//2, sj+l//2, l//2)