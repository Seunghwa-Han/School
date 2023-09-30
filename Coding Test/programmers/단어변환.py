from collections import deque

def isAdj(a, b):
    cnt = 0
    for i in range(len(a)):
        if a[i]!=b[i]:
            cnt += 1
        if cnt >1 :
            return False 
    return True 

def solution(begin, target, words):
    ans = 0
    visit = [False]*(len(words)+1)
    q = deque()
    q.append((0,0))
    visit[0]=True 
    
    while q:
        i, cnt = q.popleft()
        if i==0: w = begin
        else: w = words[i-1]
        
        if w == target:
            return cnt 
        
        for k in range(1, len(words)+1):
            if not visit[k] and isAdj(w, words[k-1]):
                visit[k]=True 
                q.append((k, cnt+1))
    return 0

'''
bfs 사용해서 shortest path 찾기 
(non-weighted graph에서)
'''