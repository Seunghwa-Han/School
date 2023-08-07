import sys 
input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(9)]

# def getNum(i, j):
#     num = set([i for i in range(1,10)])
#     num -= set([board[i][k] for k in range(9)])
#     num -= set([board[k][j] for k in range(9)])
#     x, y = 3*(i//3), 3*(j//3)
#     num -= set(board[x][y:y+3])
#     num -= set(board[x+1][y:y+3])
#     num -= set(board[x+2][y:y+3])
#     return num 

row = [[False]*10 for _ in range(9)]
col = [[False]*10 for _ in range(9)]
square = [[False]*10 for _ in range(9)]

for i in range(9):
    for j in range(9):
        if board[i][j]!=0:
            row[i][board[i][j]]=True 
            col[j][board[i][j]]=True
            square[3*(i//3)+j//3][board[i][j]]=True

def backtracking(c):
    i, j = c//9, c%9 

    if c==81:
        for line in board:
            print(' '.join(list(map(str, line))))
        return True 
    
    if board[i][j]!=0:
        return backtracking(c+1)
    
    # nums = getNum(i,j)
    # for num in nums:
    #     board[i][j]=num 
    #     if backtracking(c+1):
    #         return True 
    #     board[i][j]=0 
    for x in range(1,10):
        if not row[i][x] and not col[j][x] and not square[3*(i//3)+j//3][x]:
            row[i][x]= col[j][x]= square[3*(i//3)+j//3][x] = True 
            board[i][j]=x
            if backtracking(c+1):
                return True 
            board[i][j]=0
            row[i][x]= col[j][x]= square[3*(i//3)+j//3][x] = False 
    return False 

backtracking(0)