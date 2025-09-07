from math import gcd

def is_valid():
    n = int(input())
    p = list(map(int, input().split(" ")))
    q = list(map(int, input().split(" ")))

    # initial check
    if p[n-1] != q[0]:
        return "NO"

    val = q[0]
    # print(f"initial: {val}")

    for i in range(n-1):
        s = gcd(p[i], q[i+1])
        # print(f"gcdsum: {i} -> {s}")
        if s != val:
            return "NO"
    return "YES"
        

num_tests = int(input())
for _ in range(num_tests):
    print(is_valid())
