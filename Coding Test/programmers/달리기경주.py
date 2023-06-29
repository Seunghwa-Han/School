def solution(players, callings):
    answer = []
    d_name = {}
    d_place = {}
    for i, name in enumerate(players):
        d_name[name] = i
        d_place[i] = name
    for name in callings:
        p = d_name[name]
        d_name[name] -= 1
        d_name[d_place[p-1]] += 1
        d_place[p], d_place[p-1] = d_place[p-1], d_place[p]

    [answer.append(v) for k, v in d_place.items()]
    return answer