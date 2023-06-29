N = int(input())
A = list(map(int, input().split()))
S = int(input())

cnt = S

s = 0
while s<N-1 and cnt>0:
    m = max(A[s:s+cnt+1])
    if m == A[s]:
        s += 1
    else:
        idx = A.index(m)
        for i in range(idx, s, -1):
            A[i], A[i-1] = A[i-1], A[i]
        cnt -= idx-s
print(*A)
    
'''
1 2 3 4 5 
8번 sort 
s = 0, cnt = 8 -> cnt -= 4-0 =4
5 1 2 3 4 
s = 1, cnt = 4 -> cnt -= 4-1 =1
5 4 1 2 3
s = 2, cnt = 1 -> cnt -= 2-1 =0
5 4 2 1 3
'''