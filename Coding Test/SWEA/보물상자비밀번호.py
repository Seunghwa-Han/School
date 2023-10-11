T = int(input())

def maxNum(N, K, arr):
    nums = set()
    step = N//4
    for s in range(step):
        for i in range(0, N - step + 1, step):
            num = "".join(arr[i:i + step])
            nums.add(int(num, 16))
        n = arr.pop()
        arr.insert(0,n)

    return sorted(list(nums), reverse=True)[K-1]


for test_case in range(1, T + 1):
    N, K = map(int, input().split())
    arr = list(input())
    print(f"#{test_case} {maxNum(N, K, arr)}")