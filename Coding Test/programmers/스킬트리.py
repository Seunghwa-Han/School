def solution(skill, skill_trees):
    ans = 0
    set_s = set(skill)
    for st in skill_trees:
        idx = 0
        for s in st:
            if s not in set_s: continue
            if s == skill[idx]: 
                idx += 1
            else:
                idx = -1
                break 
        if idx != -1:
            ans += 1
    return ans

'''
idx : 비교할 스킬 순서, skill[0]으로 초기화 
skill tree를 돌면서 
- skill에 포함되지 않은 스킬이면 continue
- skill[idx]랑 다른 스킬이면 스킬 순서를 어긋난 것이므로 break 
'''