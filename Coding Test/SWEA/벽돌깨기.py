def action(arr, now):
    x,y=-1,now
    for i in range(len(arr)):
        if arr[i][now]!=0:
            x = i
            break
    # 터뜨리기 
    bubble(x,y,arr)
    # 빈 곳 메꾸기 
    for j, col in enumerate(zip(*arr)):
        zeros = col.count(0)
        new_col = [0]*zeros + [c for c in col if c!=0]
        for i in range(len(arr)):
            arr[i][j] = new_col[i]
    return arr
def bubble(x,y,arr):
    cnt = arr[x][y]-1
    arr[x][y] = 0
    if cnt ==0:
        return
    for j in range(y-cnt, y+cnt+1):
        if 0<=j<len(arr[0]) and arr[x][j]!=0:
            bubble(x,j,arr)
    for i in range(x-cnt, x+cnt+1):
        if 0<=i<len(arr) and arr[i][y]!=0:
            bubble(i,y,arr)

ans = None
def recur(arr, cnt):
    global ans
    if cnt==0:
        zeros = 0
        for row in arr:
            zeros += row.count(0)
        ans = min(len(arr[0])*len(arr)-zeros, ans)
        return 

    for j in range(len(arr[0])):
        tmp = [arr[i][:] for i in range(len(arr))]
        action(tmp, j)
        recur(tmp, cnt-1)

T = int(input())
for test_case in range(1, T + 1):
    N, W, H = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(H)]
    ans = W*H+1
    recur(arr, N)
    print(f"#{test_case} {ans}")