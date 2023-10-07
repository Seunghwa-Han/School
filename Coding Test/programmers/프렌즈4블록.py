def solution(m, n, board):
    ans = 0
    b = [[board[i][j] for j in range(n)] for i in range(m)]
    while 1:
        if not find2x2(m,n,b): break 
    
    for i in range(m):
        ans += b[i].count('.')
    return ans

def find2x2(m,n,b):
    flag = False  
	# 4block찾기 
    tmp = [[b[i][j] for j in range(n)] for i in range(m)]
    for i in range(m-1):
        for j in range(n-1):
            if b[i][j]=='.': continue
            if b[i][j]==b[i][j+1]==b[i+1][j]==b[i+1][j+1]:
                flag = True  
                tmp[i][j]='.'
                tmp[i+1][j]='.'
                tmp[i][j+1]='.'
                tmp[i+1][j+1]='.'
	# 아래로 밀기 
    st = []
    for j in range(n):
        for i in range(m):
            if tmp[i][j]!='.':
                st.append((i,j))
        i = m-1
        while st:
            x,y = st.pop()
            b[i][j] = b[x][y]
            i -= 1
        while i>=0:
            b[i][j]='.'
            i -= 1
    return flag
'''
4block을 찾은 다음에 아래로 미는 과정 ?? 
-> Stack으로 한 열에 공백이 아닌 블럭을 전부 추가하고
추가한 블럭은 공백으로 치환 후
스택이 비어있지 않다면 순차적으로 pop하여 아랫부분부터 채워줬습니다.
https://school.programmers.co.kr/questions/54233 참고 

이차원 배열 deepcopy
- list내장의 copy()를 사용하면 deepcopy가 안된다 
'''