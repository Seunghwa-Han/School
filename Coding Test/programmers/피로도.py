answer = -1
ans = set()
def dfs(dungeons, k):
    global answer 
    
    answer = max(answer, len(ans))
    
    for i in range(len(dungeons)):
        if i not in ans and k>=dungeons[i][0]:
            ans.add(i)
            dfs(dungeons, k-dungeons[i][1])
            ans.remove(i)

def solution(k, dungeons):
    dfs(dungeons, k)
    
    return answer