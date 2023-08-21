import sys 
input = sys.stdin.readline 

N, M = map(int, input().split())
tree = list(map(int, input().split()))
tree.sort()

s = 0
e = max(tree)
ans = 0
while s<=e:
    mid = (s+e)//2
    
    sum_val = sum(list(map(lambda x: x-mid if x>mid else 0, tree)))
    if sum_val == M:
        ans = mid 
        break 
    elif sum_val > M:
        ans = mid 
        s = mid+1 
    else:
        e = mid-1
print(ans)
