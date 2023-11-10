'''
backtracking 사용해서 풀었음 
처음엔 그냥 dia, iron, stone 순으로 사용하면 되겠지 생각했는데 >> 아님 !! 
광물 [돌,돌,돌,돌,돌,철] -> 이 상태에서 곡괭이[0,1,1]가 이렇게 주어지면 
돌을 먼저 쓰고 철을 쓰는게 더 데미지가 적음 
'''
answer = 50*25
dic = dict()
def solution(picks, minerals):
    global dic 
    dic[(0, "diamond")]=1
    dic[(0, "iron")]=1
    dic[(0, "stone")]=1
    dic[(1, "diamond")]=5
    dic[(1, "iron")]=1
    dic[(1, "stone")]=1
    dic[(2, "diamond")]=25
    dic[(2, "iron")]=5
    dic[(2, "stone")]=1
    
    bt(0, 0, picks, minerals)
    
    return answer

def bt(m, cnt, picks, minerals):
    global answer 
	# 더 이상 캘 광물이 없거나 or 사용할 곡갱이가 없으면 종료 
	# sum(picks)==0 >> 이렇게 하면 더 코드 간결 
    if m>=len(minerals) or (picks[0]==0 and picks[1]==0 and picks[2]==0):
        answer = min(answer, cnt)
        return 
    
    for p in range(3):
        if picks[p]==0: continue 
        tmp = cnt 
        for i in range(m, m+5):
            if i >= len(minerals): break 
            tmp += dic[(p, minerals[i])]
        picks[p]-=1
        bt(m+5, tmp, picks, minerals)
        picks[p]+=1

'''
밑에 코드 보고 내 코드 간결하게 수정했음 
'''
answer = 50*25
dic = dict()
def solution(picks, minerals):
    # ...
    
    bt(0, picks, minerals)
    
    return answer

def bt(cnt, picks, minerals):
    global answer 
    if len(minerals)==0 or sum(picks)==0:
        answer = min(answer, cnt)
        return 
    
    for p in range(3):
        if picks[p]==0: continue 
        picks[p]-=1
        bt(cnt+sum(dic[(p, m)] for m in minerals[:5]), picks, minerals[5:])
        picks[p]+=1

'''
이렇게 코드 짤 수도 있음 https://school.programmers.co.kr/learn/courses/30/lessons/172927/solution_groups?language=python3
minerals의 index를 파라미터로 넘기는 것이 아니라 
minerals배열을 indexing해서 넘겨도 됨 
'''
def solution(picks, minerals):
    def solve(picks, minerals, fatigue):
        if sum(picks) == 0 or len(minerals) == 0:
            return fatigue
        result = [float('inf')]
        for i, fatigues in enumerate(({"diamond": 1, "iron": 1, "stone": 1},
                                      {"diamond": 5, "iron": 1, "stone": 1},
                                      {"diamond": 25, "iron": 5, "stone": 1},)):
            if picks[i] > 0:
                temp_picks = picks.copy()
                temp_picks[i] -= 1
                result.append(
                    solve(temp_picks, minerals[5:], fatigue + sum(fatigues[mineral] for mineral in minerals[:5])))
        return min(result)

    return solve(picks, minerals, 0)