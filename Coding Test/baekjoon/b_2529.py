import sys
input = sys.stdin.readline
k = int(input()) # 2 ≤ k ≤ 9
op = list(input().split())
op.insert(0, '<=')

max_v = 0
min_v = 1e10

def func(idx, value):
	global max_v, min_v
	if idx == k+1:
		max_v = max(max_v, int(value.lstrip('0')))
		min_v = min(min_v, int(value.lstrip('0')))
		return 
	
	for i in range(0, 10):
		if value.count(str(i), 1) == 0 and eval(value[-1]+op[idx]+str(i)):
			func(idx+1, value+str(i))

func(0, "0")
print(str(max_v).zfill(k+1))
print(f'{min_v:0{k+1}d}')