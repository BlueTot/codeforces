num_tests = int(input())
for _ in range(num_tests):
    n, k = map(int, input().split(" "))
    s = list(map(int, input().split(" ")))
    t = list(map(int, input().split(" ")))

    def toAbs(arr):
        counter = {}
        for n in arr:
            mod = min(n % k, k - (n % k))
            counter[mod] = counter.get(mod, 0) + 1
        return counter

    absS, absT = toAbs(s), toAbs(t)
    if absS == absT:
        print("YES")
    else:
        print("NO")

