from math import gcd

num_tests = int(input())

def minops(nums):

    gcds = set(i for i in range(len(nums)))
    
    def gcds_of(s, nums):
        s = list(s)
        if len(s) == 0: return 0
        if len(s) == 1: return nums[s[0]]
        curr = nums[s[0]]
        for i in s[1:]:
            curr = gcd(curr, nums[i])
        return curr

    allgcds = gcds_of(gcds, nums)
    # print("all", allgcds)

    for i in range(len(nums)):
        # print(i)
        gcds.remove(i)
        if gcds_of(gcds, nums) != allgcds:
            gcds.add(i)
    # print(gcds)

    count = 0
    for n in nums:
        if n != allgcds:
            count += 1
    # print(count, len(gcds))

    return max(len(gcds) - 1, 1) + count - 1


for _ in range(num_tests):
    n = int(input())
    nums = list(map(int, input().split(" ")))
    print(minops(nums))

