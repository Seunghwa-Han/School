num = input().split('-')

res = 0
for i in range(0, len(num)):
    sums = num[i].split('+')
    sum = 0
    for n in sums:
        sum += int(n)
    if i==0:
        res += sum
    else:
        res -= sum
print(res)