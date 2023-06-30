N = int(input()) # N<=50 
num = list(map(int, input().split()))

num.sort()

while True:
    flag = 0
    for i in range(N-1):
        if num[i]+1 == num[i+1]:
            flag = 1
            tmp = num[i+1]
            for j in range(i+2, N):
                if num[i]+1 != num[j] and num[i]!=num[j]:
                    num[i+1], num[j] = num[j], num[i+1]
                    break
            if tmp == num[i+1]:
                 num[i], num[i+1] = num[i+1], num[i]
    
    if flag == 0:
        break
print(*num)