def solution(people, limit):
    answer = 0
    people.sort(key=lambda x: -x)
    
    i= 0
    j= len(people)-1
    while i<=j:
        if people[i]+people[j]<=limit:
            i +=1
            j -=1
        else:
            i += 1
        answer += 1
        
    return answer

def solution(people, limit):
    ans = 0
    people.sort()
    
    s, e = 0, len(people)-1
    while s<=e:
        if people[s]+people[e]<=limit:
            s += 1
        e -= 1
        ans += 1
    return ans
'''
limit = 100
10,20,50,60,90

30,50,70,80
'''