from collections import deque
def solution(queue1, queue2):
    answer = 0
    target = (sum(queue1)+sum(queue2))//2
    
    q1 = deque(queue1)
    q2 = deque(queue2)
    
    q1_sum = sum(q1)
    cnt = 0
    while 1:
        if q1_sum <= 0 or cnt > 600000:
            answer = -1
            break 
        elif q1_sum == target:
            if sum(q2) != target:
                answer = -1
            break 
        else:
            answer += 1
            
            if q1_sum < target:
                tmp = q2.popleft()
                q1.append(tmp)
                q1_sum += tmp
            elif q1_sum > target:
                tmp = q1.popleft()
                q2.append(tmp)
                q1_sum -= tmp
        cnt += 1
            
        
    return answer

def solution_final(queue1, queue2):
    answer = 0
    target = (sum(queue1)+sum(queue2))//2
    
    q = queue1+queue2+queue1
    s = 0
    e = len(queue1)-1
    cur = sum(queue1)
    while True:
        if cur == target:
            break 
        if cur < target:
            e += 1
            if e >= len(q):
                answer = -1
                break 
            cur += q[e]
        elif cur > target:
            cur -= q[s]
            s += 1
        answer += 1
        
    return answer

'''
3,2,7,2 : 14
4,6,5,1 : 16 
-> 15
첫번째에서 3 pop,ins
두번째에서 4 pop, ins

3+2+7+2=14 < 15이므로 다른 큐에서 하나 가져옴 
14+4 = 18 > 15이므로 맨 앞에서 팝 해서 뺌 
18-3= 15 

1,2,1,2 : 6
1,10,1,2 :14
-> 10
두번째에서 1,10 pop,ins
첫번째에서 1,2,1,2,1 pop,ins

1+2+1+2 = 6 <10이므로 다른 큐에서 하나 가져옴
6+1 = 7<10 이므로 다른 큐에서 하나 가져옴
7+10=17 >10 이므로 맨 앞에서 팝해서뺌
17-1=16 >10이므로 맨 앞에서 팝해서뺌
16-2=14 >10이므로 맨 앞에서 팝해서뺌
14-1=13 >10이므로 맨 앞에서 팝해서뺌
13-2=11 >10이므로 맨 앞에서 팝해서뺌
11-1=10 


1,1 :2
1,5 :6
-> 4

1+1=2 <4이므로 다른 큐에서 하나 가져옴
2+1=3 <4이므로 다른 큐에서 하나 가져옴 
3+5=8 >4이므로 맨 앞에서 팝해서뺌
8-1=7 >4이므로 맨 앞에서 팝해서뺌
7-1=6 >4이므로 맨 앞에서 팝해서뺌
6-1=5 >4이므로 맨 앞에서 팝해서뺌
5-5=0 : 불가능 

101,100
102,103
무한루프 
4번 시행 -> 102,103 101,100 돌아옴 
'''