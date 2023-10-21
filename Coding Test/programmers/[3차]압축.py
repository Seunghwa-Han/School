def solution(msg):
    ans = []
    d = list(map(chr, range(ord('A'), ord('Z')+1)))
    
    w=0
    while w<len(msg):
        num = -1
        for i in range(len(d)):
            if  msg[w:].startswith(d[i]):
                if num == -1 or len(d[num]) < len(d[i]):
                    num = i 

        ans.append(num+1)
        if w<len(msg)-1:
            new_w = msg[w:w+len(d[num])+1]
            d.append(new_w)
        w += len(d[num])
        
    return ans
'''
딱히 알고리즘 없고 그냥 구현하는 거 

https://school.programmers.co.kr/questions/55199 
이렇게 풀 수도 있음 !! 

{k:v for (k,v) in zip(alphabet, list(range(1,27)))}
{chr(e + 64): e for e in range(1, 27)}
이렇게 dictionary 만들 수도 있음 

https://school.programmers.co.kr/learn/courses/30/lessons/17684/solution_groups?language=python3
이런 코드도 있음 (위에서 1번째랑 2번째 코드 참고)
'''