import sys
import heapq
N = int(sys.stdin.readline().strip())

heap = []

for _ in range(N):
    x = int(sys.stdin.readline().strip())
    if x == 0:
        if not heap:
            print(0)
        else:
            del_item = heapq.heappop(heap)[1]
            print(del_item)
    else:
        heapq.heappush(heap, (-x, x))