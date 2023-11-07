# 정답 봤음 .. https://school.programmers.co.kr/questions/49124
from collections import defaultdict 
from itertools import product
from bisect import bisect_left 
            
def solution(info, query):
    answer = []
    
    info = [tuple(i.split()) for i in info]
    queries = [tuple(q_ for q_ in q.split() if q_!="and") for q in query]

    dic = defaultdict(list)
    for entry in info:
        for p in product(*tuple(("-",e) for e in entry[:-1])):
            dic[p].append(int(entry[-1]))
    for record in dic:
        dic[record].sort()
    
    for query in queries:
        q, s = query[:-1], int(query[-1])
        ans = len(dic[q]) - bisect_left(dic[q], s)
        answer.append(ans)
    return answer

'''
처음 내가 생각한 방법 
- dict[java], dict[python], dict[cpp]
...
이런 식의 딕셔너리에 index를 추가해서 쿼리가 주어지면 &연산 교집합해서 몇 명인지 알아내려고 했음 ..
근데 그렇게 하면 효율성 통과가 안됨 ㅜㅜ .. 

제안되는 방법 
- dict[-][-][-][pizza], dict[-][-][-][chicken],... 
이런 식으로 4*3*3*3 개의 key를 가지는 딕셔너리를 생성하고 딕셔너리 value type은 list
value로는 score를 넣어줌 
그리고 value들을 sort해주면 binary search 사용해서 문제 쉽게 풀 수 있음 

https://school.programmers.co.kr/learn/courses/30/lessons/72412/solution_groups?language=python3
이런 코드도 있습니다 
로직은 위의 코드와 똑같음 
'''
def solution(info, query):
    data = dict()
    for a in ['cpp', 'java', 'python', '-']:
        for b in ['backend', 'frontend', '-']:
            for c in ['junior', 'senior', '-']:
                for d in ['chicken', 'pizza', '-']:
                    data.setdefault((a, b, c, d), list())
    for i in info:
        i = i.split()
        for a in [i[0], '-']:
            for b in [i[1], '-']:
                for c in [i[2], '-']:
                    for d in [i[3], '-']:
                        data[(a, b, c, d)].append(int(i[4]))

    for k in data:
        data[k].sort()

        # print(k, data[k])

    answer = list()
    for q in query:
        q = q.split()

        pool = data[(q[0], q[2], q[4], q[6])]
        find = int(q[7])
        l = 0
        r = len(pool)
        mid = 0
        while l < r:
            mid = (r+l)//2
            if pool[mid] >= find:
                r = mid
            else:
                l = mid+1
            # print(l, r, mid, answer)
        # answer.append((pool, find, mid))
        answer.append(len(pool)-l)

    return answer