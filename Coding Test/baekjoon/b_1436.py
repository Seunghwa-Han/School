n = int(input())

i = 666
while n >0:
    if "666" in str(i):
        n -= 1
    i += 1
print(i-1)
'''
n <= 10000 : O(n^2)
'''