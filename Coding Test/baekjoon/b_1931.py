N = int(input())

list = [tuple(map(int, input().split())) for _ in range(N)]

list.sort(key = lambda x : (x[1], x[0]))

cnt = 1 
start = list[0][0]
finish = list[0][1]

for l in list[1:]:
    if finish <= l[0]:
        start = l[0]
        finish = l[1]
        cnt += 1

print(cnt)

'''
2
9 9
1 9
-> 2 
greedy 
finish time이 가장 빠른 것부터
finish time이 tie이면 start time이 가장 빠른 것부터 
'''