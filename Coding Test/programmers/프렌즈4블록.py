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

def solution(m, n, board):
    x = board
    x2 =[]

    for i in x: 
        x1 = []
        for i2 in i:
            x1.append(i2)
        x2.append(x1)

    point = 1
    while point != 0:
        list = []
        point = 0
        for i in range(m - 1):
            for j in range(n - 1):
                if x2[i][j] == x2[i][j + 1] == x2[i + 1][j] == x2[i + 1][j + 1] != '팡!':
                    list.append([i, j])
                    point += 1

        for i2 in list:
            i, j = i2[0], i2[1]
            x2[i][j], x2[i][j + 1], x2[i + 1][j], x2[i + 1][j + 1] = '팡!', '팡!', '팡!', '팡!'

        for i3 in range(m):
            for i in range(m - 1):
                for j in range(n):
                    if x2[i + 1][j] == '팡!':
                        x2[i + 1][j], x2[i][j] = x2[i][j], '팡!'

    cnt = 0
    for i in x2:
        cnt += i.count('팡!')
    return cnt
'''
>> 다른 사람 코드 
4block찾고 아래로 당기는 부분  
: 아래칸이 4block이면 위아래 교환하는 작업을 m번 반복함 
'''

def pop_num(b, m, n):
    pop_set = set()
    # search
    for i in range(1, n):
        for j in range(1, m):
            if b[i][j] == b[i - 1][j - 1] == b[i - 1][j] == b[i][j - 1] != '_':
                pop_set |= set([(i, j), (i - 1, j - 1), (i - 1, j), (i, j - 1)])
    # set_board
    for i, j in pop_set:
        b[i][j] = 0
    for i, row in enumerate(b):
        empty = ['_'] * row.count(0)
        b[i] = empty + [block for block in row if block != 0]
    return len(pop_set)

def solution(m, n, board):
    count = 0
    b = list(map(list, zip(*board)))  # 행열 바꿔치기
    while True:
        pop = pop_num(b, m, n)
        if pop == 0: return count
        count += pop
'''
>> 다른 사람 코드 
계산 편하게 하려고 board 행열 바꾸었음 (line107)
4block찾고 아래로 당기는 부분: line100~102
	아예 새로 만들어서 b[i]에 assign 해주었음 
'''