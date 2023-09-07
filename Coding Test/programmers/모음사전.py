def change(w):
    dic = {"A":"E", "E":"I", "I":"O", "O":"U"}
    w = w[:-1]+dic.get(w[-1])
    return w
def solution(word):
    dic = {"A":0, "E":1, "I":2, "O":3, "U":4}
    answer = 781*dic.get(word[0])+1
    
    w = word[0]
    
    while w != word:
        if len(w)<5:
            w += "A"
        else:
            while w[-1]=="U":
                w = w[:-1]
            w = change(w)
            
        answer += 1
    return answer

    