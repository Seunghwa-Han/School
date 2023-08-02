import sys 
input = sys.stdin.readline
A, B, C, X, Y = map(int, input().split())
# 양념 치킨 최소 X마리, 후라이드 치킨 최소 Y마리 
# 양념A, 후라이드B, 반반C 

if A+B < C*2:
	ans = A*X + B*Y 
else:
	if X < Y:
		ans = C*X*2 + B*(Y-X)
	else:
		ans = C*Y*2 + A*(X-Y)
	ans = min(ans, C*max(X,Y)*2)

print(ans)