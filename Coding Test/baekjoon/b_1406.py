'''
sys.stdin.readline 사용하니까 파이썬 시간초과가 해결되었음 
단 readline 사용하면 개행문자도 같이 입력받아지는 것 주의하기 !
'''
import sys
input = sys.stdin.readline
line = input().strip()
M = int(input())

st = list(line)
left = []
for _ in range(M):
  command = input().strip()
  if command == "L" and st:
    left.append(st.pop())
  elif command == "D" and left:
    st.append(left.pop())
  elif command == "B" and st:
    st.pop()
  elif command[0] == "P":
    st.append(command[2])

print("".join(st) + "".join(left[::-1]))