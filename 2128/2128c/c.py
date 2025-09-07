num_tests = int(input())
for _ in range(num_tests):
    n = int(input())
    nums = list(map(int, input().split(" ")))
    smallest = float("inf")
    for x in nums:
        if x >= 2 * smallest:
            print("NO")
            break
        smallest = min(smallest, x)
    else:
        print("YES")

