import sys 
input = sys.stdin.readline 

N = int(input()) # 2 ≤ N ≤ 100
channels = [input().rstrip() for _ in range(N)]

if channels[0] != "KBS1":
	i = 0 
	while 1:
		print("1",end="")
		if channels[i+1]=="KBS1":
			print("4"*(i+1), end="")
			break 
		i += 1
channels.remove("KBS1")
print("1", end="")
if channels[0] != "KBS2":
	i = 0
	while 1:
		print("1",end="")
		if channels[i+1]=="KBS2":
			print("4"*(i+1))
			break 
		i += 1