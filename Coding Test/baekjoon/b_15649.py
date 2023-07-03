N, M = map(int, input().split())
ans = []
def backtracking(d):
    if d== M:
        print(' '.join(map(str, ans)))
        return 
    for i in range(1, N+1):
        if i not in ans:
            ans.append(i)
            backtracking(d+1)
            ans.pop()
backtracking(0)

# from itertools import permutations

# combi = list(permutations([i for i in range(1,N+1)], M))
# [print(*_) for _ in combi]