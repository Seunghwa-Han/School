arr = [list(map(int, input().split())) for _ in range(5)]

win = 0
score = 0
for i in range(5):
    sum = 0
    for j in range(4):
        sum += arr[i][j]
    if score < sum:
        score = sum 
        win = i
    

print(win+1, score)