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

    flag = False
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
            flag = True 
            break
    # recursion 호출 반환값이 true이면 성공이므로 return true
    # 반환값이 true가 아니라면 잘못된 경로로 온 것이므로 return false 
    return flag
'''
https://school.programmers.co.kr/questions/33058
[예외 test case]
- 중복티켓
- 사전순으로 갔을 때 길이 막혀서 다른 길을 선택해야 하는 경우

1. 처음에 dictionary의 value를 set으로 구성했다 -> 중복티켓 고려못함 
2. dictionary value를 역순으로 정렬시켜 놓고 
    뒤에서부터 반복문돌면서 함수 호출 
'''