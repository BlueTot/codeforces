num_tests = int(input())
for _ in range(num_tests):
    n = int(input())
    nums = list(map(int, input().split(" ")))
    result = []
    i = 0
    j = len(nums) - 1
    while i <= j:
        if len(result) % 2 == 0: # choose smallest
            result.append("L" if nums[i] < nums[j] else "R")
        else: # choose largest
            result.append("L" if nums[i] > nums[j] else "R")
        if result[-1] == "L":
            i += 1
        else:
            j -= 1
    print("".join(result))
