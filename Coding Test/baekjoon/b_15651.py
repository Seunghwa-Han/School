N, M = map(int, input().split())
# from itertools import product

# combi = list(product([i for i in range(1,N+1)], repeat=M))
# [print(*_) for _ in combi]

ans = []
def backtracking(d):
    if d == M:
        print(' '.join(map(str, ans)))
        return
    for i in range(1, N+1):
        ans.append(i)
        backtracking(d+1)
        ans.pop()
backtracking(0)