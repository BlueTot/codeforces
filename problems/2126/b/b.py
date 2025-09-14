num_tests = int(input())
for _ in range(num_tests):
    n, k = list(map(int, input().split(" ")))
    nums = list(map(int, input().split(" ")))
    count = 0
    run = 0
    for i in range(n):
        if nums[i] == 0:
            run += 1
        else:
            # kn + (n-1) = (k+1)n - 1
            count += (run + 1) // (k + 1)
            run = 0
    # end check
    if run > 0: count += (run + 1) // (k + 1)

    print(count)


