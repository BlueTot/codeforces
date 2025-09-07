import math

num_tests = int(input())
for _ in range(num_tests):
    # print(f"Test case: {_+1}")

    n, c = list(map(int, input().split(" ")))
    nums= list(map(int, input().split(" ")))

    def num_times(x, c):
        v = math.log2(c/x)
        if v < 0:
            return -1
        else:
            return math.floor(v)

    data = sorted([num_times(x, c) for x in nums])
    # data2  = sorted([x for x in data if x > 0])

    # print(data)

    lis = [0 for _ in data]
    for i in range(len(data)):
        longest = 0
        for j in range(i):
            if data[j] <= data[i] and data[i] - lis[j] >= 0:
                longest = max(longest, lis[j])
        if longest > 0:
            lis[i] = 1 + longest
        elif data[i] >= 0:
            lis[i] = 1
    # print(lis)
    print(len(data) - max(lis))
