import sys 
input = sys.stdin.readline 

def getOnes(n):
    ans = []
    index = 0 
    while 1:
        r = n//2 
        s = n%2
        if s == 1:
           ans.append(index)
        index += 1
        n = r 
        if r == 0:
            break 
    return ans   

T = int(input())
for _ in range(T):
    n = int(input())
    print(*getOnes(n))