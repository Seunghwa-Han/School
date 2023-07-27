N, K = map(int, input().split()) # 1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000
coin = [int(input())for _ in range(N)]

now = K
ans = 0
while now > 0:

	max_value = coin[-1]
	
	if now-max_value < 0:
		coin.pop()
	else:
		cnt = now//max_value
		now -= cnt*max_value
		ans += cnt
print(ans)