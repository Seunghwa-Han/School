N, M = map(int, input().split())
board = [input() for _ in range(N)]

chess1 = ["WBWBWBWB", "BWBWBWBW"]
chess2 = ["BWBWBWBW", "WBWBWBWB"]
ans = 50*50
for i in range(N-7):
    for j in range(M-7):
        cnt1 = cnt2 = 0
        for x in range(8):
            for y in range(8):
                if chess1[x%2][y]!=board[i+x][j+y]:
                    cnt1 += 1
                if chess2[x%2][y]!=board[i+x][j+y]:
                    cnt2 += 1
        ans = min(ans, cnt1, cnt2)

print(ans)