import sys
N, K = map(int, sys.stdin.readline().split()) # 1 ≤ K < N ≤ 500,000
number = list(sys.stdin.readline().strip())

ans = []
cnt = 0
for num in number:
    while ans and cnt<K and num > ans[-1]:
        del ans[-1]
        cnt += 1
    ans.append(num)

'''
5 1
54321 
그냥 ans 아니고 ans[:N-K] 해주어야 함 
'''
print(''.join(ans[:N-K]))