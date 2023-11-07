def solution(topping):
    ans = 0
    
    tmp = set()
    a = [0 for _ in range(len(topping))]
    b = [0 for _ in range(len(topping))]
    for i in range(len(topping)):
        tmp.add(topping[i])
        a[i] = len(tmp)
    tmp = set()
    for i in range(len(topping)-1, -1, -1):
        tmp.add(topping[i])
        b[i] = len(tmp)
    
    for i in range(len(topping)-1):
        if a[i] == b[i+1]:
            ans += 1
        elif ans>0: break
        
    return ans
'''
앞 뒤로 배열 2개 만드는거 말고 다른 방식으로 하고 싶었는데 ..
'''

from collections import Counter
def solution(topping):
    ans = 0
    
    dic = Counter(topping)
    s = set()
    
    for i in range(len(topping)-1):
        dic[topping[i]] -= 1
        s.add(topping[i])
        if dic[topping[i]]==0:
            dic.pop(topping[i])
        if len(s)==len(dic): ans+=1
    return ans
'''
Counter를 사용하면 value가 0보다 큰거 셀 때 O(n)걸리니까 걱정이었는데 
값이 0이 되면 그 key를 dic에서 pop하면 됨 !! line35,36 

https://school.programmers.co.kr/learn/courses/30/lessons/132265/solution_groups?language=python3
참고 
'''