import sys 
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
M = int(input())
nums = list(map(int, input().split()))

A.sort()
def findNum(num):
    length = len(A)
    
    s = 0 
    e = len(A)-1
    while s<=e:
        mid = s+(e-s)//2
        
        if num == A[mid]:
            return 1 
        elif num < A[mid]:
            e = mid-1 
        else:
            s = mid+1 
    return 0
            
for num in nums:
    print(findNum(num))