N = int(input())
A = [int(input()) for _ in range(N)]

sum_max = 0

f = [0]*N # 지금껏 마신 포도주 배열 

for i in range(N):
    if i == 0:
        f[0] = A[0]
    elif i == 1:
        f[1] = f[0]+A[1]
    elif i == 2:
        f[2] = max(A[2]+A[1], A[2]+f[0], f[1])
    else:
        f[i] = max(A[i]+A[i-1]+f[i-3], A[i]+f[i-2], f[i-1])

print(f[N-1])

'''
f(n) = An + A_(n-1) + f(n-3)
f(n) = An + f(n-2)
f(n) = f(n-1)
'''