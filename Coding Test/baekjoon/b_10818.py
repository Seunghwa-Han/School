N = int(input()) # 1 ≤ N ≤ 1,000,000

arr = list(map(int, input().split()))

max = arr[0]
min = arr[0]
for i in arr:
    if max < i:
        max = i 
    if min > i:
        min = i 

print(min, max)