from math import ceil

def run():
    n, m, k = map(int, input().split())

    def isValid(d):
        return ceil(n / ( 2* d + 1)) * ceil(m / ( 2 * d + 1)) <= k

    left, right = 0, n * m
    while left < right:
        mid = (left + right) // 2
        if isValid(mid):
            right = mid
        else:
            left = mid + 1
    return left

print(run())
