def is_open(ch):
    return ch == "(" or ch == "[" 
def is_close(ch):
    return ch == ")" or ch == "]"
def is_match(ch1, ch2):
    return ch1=="(" and ch2==")" or ch1=="[" and ch2=="]"

while 1:
    line = input()
    if line == ".": 
        break 

    stack = []
    ans = "yes"
    for ch in line:
        if is_open(ch):
            stack.append(ch)
        elif is_close(ch):
            if stack and is_match(stack[-1], ch):
                stack.pop()
            else:
                ans = "no"
                break 
    if stack: ans = "no"
    print(ans)
'''
전형적인 stack으로 괄호체크하는 문제
처음에 line24를 빼먹어서 통과안됐다  (()같은 case 
'''