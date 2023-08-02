import sys 
input = sys.stdin.readline

N = int(input()) # 1 ≤ N ≤ 20
ans = set()
nums = (1, 5, 10, 50)
visited = [False]*4

def func(cnt, val, t):
	if cnt==N:
		ans.add(val)
		return 
	for n in nums:
		if n >= t:
			func(cnt+1, val+n, n)
func(0, 0, 0)
print(ans)
print(len(ans))
'''
N=3 -> 20
1,5,10,50
1/1/1
1/1/5
1/1/10
1/1/50
1/5/5
1/5/10
1/5/50
1/10/10
1/10/50
1/50/50

5/5/5
5/5/10
5/5/50
5/10/10
5/10/50
5/50/50

10/10/10
10/10/50
10/50/50
50/50/50
'''