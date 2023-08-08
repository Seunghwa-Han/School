import sys 
input = sys.stdin.readline 

N = int(input())
P = list(map(int, input().split()))

ans = 0
P.sort()
for i in range(N):
    ans += sum(P[:i+1])
print(ans)