rest = 1000-int(input())
money = [500,100,50,10,5,1]
ans = 0
for m in money:
    tmp = rest//m
    rest -= tmp*m
    ans += tmp 
print(ans) 