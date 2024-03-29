cnt =0 
def solution(tickets):
    global cnt 
    cnt = len(tickets)
    ans = ["ICN"]
    d = dict()
    
    for a,b in tickets:
        if not d.get(a):
            d[a]=[b]
        else:
            d[a].append(b)
    
    for k in d.keys():
        d[k].sort(reverse=True)
    
    dfs("ICN", d, ans)
    
    return ans

def dfs(fly, d, ans):
    global cnt
    if cnt==0: # 모든 edge를 소비한 경우 성공 
        return True
    elif not d.get(fly): # 모든 edge를 소비하지 않았는데 갈 곳이 없는 경우 실패 (다시 돌아가야함)
        return False

    for i in range(len(d[fly])-1, -1,-1):
        next = d[fly][i]
        d[fly].remove(next)
        ans.append(next)
        cnt -= 1 
        r = dfs(next, d, ans)
        if not r: 
            # 잘못된 경로이므로 
            # ans에서 경로 삭제하고, dictionary에 다시 경로 추가 
            ans.pop()
            d[fly].append(next)
            cnt += 1
        else:
            return True 
    # recursion 호출 반환값이 true이면 성공이므로 return true
    # 반환값이 true가 아니라면 잘못된 경로로 온 것이므로 return false 
    return False
'''
https://school.programmers.co.kr/questions/33058
[예외 test case]
- 중복티켓
- 사전순으로 갔을 때 길이 막혀서 다른 길을 선택해야 하는 경우

1. 처음에 dictionary의 value를 set으로 구성했다 -> 중복티켓 고려못함 
2. dictionary value를 역순으로 정렬시켜 놓고 
    뒤에서부터 반복문돌면서 함수 호출 
    반복문 사용-> 사전순으로 앞선 경로로 가면 모든 edge를 순회못할경우 다른 길로 가야하기 때문에 

    
그냥 dict 사용하면 key가 없을 때 key error가 뜨니까 defaultdict를 사용하자 ..!
'''

cnt =0 
def solution(tickets):
    global cnt 
    cnt = len(tickets)
    d = dict()
    
    for a,b in tickets:
        if not d.get(a):
            d[a]=[b]
        else:
            d[a].append(b)
        d[a].sort()
    
    ans = dfs("ICN", d, ["ICN"])
    
    return ans

def dfs(fly, d, ans):
    global cnt
    if cnt==0: 
        return ans
    elif not d.get(fly):
        return False

    for i, next in enumerate(d[fly]):
        d[fly].pop(i)
        tmp = ans[:]
        tmp.append(next)
        cnt -= 1 
        r = dfs(next, d, tmp)
        

        d[fly].insert(i, next)
        cnt += 1
        if r:
            return r
    return False 

'''
https://school.programmers.co.kr/learn/courses/30/lessons/43164/solution_groups?language=python3
첫번째 코드보고 조금 수정해봤음 
- 반복문 안에서 return 값이 false일때만 경로 삭제해주지 않아도 됨 -> recursion을 다 돌고 return 되었다는 거는 해당경로를 통해 dfs를 다 한거니까
- return값이 true일때는 경로집합(ans)를 리턴해주면됨 !! 
다 돌지 못하는 경우는 없으니까 최종 return값이 false인 경우는 없음 

return false해주는 부분 사실 필요없는데 (return값 없으면 None이 리턴되니까)
key error때문에 추가해주었음 
여러모로 defaultdict을 사용하는게 편할듯..!!
'''