import sys 
input = sys.stdin.readline 

K, N = map(int, input().split())
lans = [int(input()) for _ in range(K)]

s = 1
e = max(lans)
ans = 0
while s <= e:
    mid = (s+e)//2
    cnt = 0
    for lan in lans:
        cnt += lan//mid 
    
    if cnt >= N:
        ans = mid 
        s = mid + 1
    else:
        e = mid - 1

print(ans)