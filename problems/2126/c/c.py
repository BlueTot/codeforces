num_tests = int(input())
for _ in range(num_tests):
    n, k = list(map(int, input().split(" ")))
    k -= 1 # convert to 0-based
    nums = list(map(int, input().split(" ")))
    start = nums[k]
    nums = list(set(i for i in sorted(nums) if i >= start))
    water = 1
    for i in range(len(nums)):
        if i == len(nums)-1:
            print("YES")
            break
        else:
            dh = nums[i+1] - nums[i]
            dw = nums[i] - water
            if dh - dw > 1:
                print("NO")
                break
            water += nums[i+1] - nums[i]
            
            


