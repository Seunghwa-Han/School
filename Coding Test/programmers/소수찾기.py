from itertools import permutations 

def solution(numbers):
    answer = 0
    
    s = set()
    for i in range(1, len(numbers)+1):
        # for num in list(permutations(list(numbers), i)):
        #     n = "".join(num).lstrip('0')
        #     if n and int(n)>=2:
        #         res.add(n)
		s.add(map(int, map("".join, permutations(list(numbers), i))))
	s -= set(i for i in range(0,2))
	
    for n in s:
        n = int(n)
        if n==2 or (n!=2 and n%2!=0):
            flag = True
            for i in range(2, int(n/2)):
                if n % i == 0:
                    flag = False
                    break
            if flag:
                answer += 1

    return answer