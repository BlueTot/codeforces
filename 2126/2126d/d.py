num_tests = int(input())
for _ in range(num_tests):
    n, k = list(map(int, input().split(" ")))
    casinos = []
    for _ in range(n):
        casinos.append(tuple(map(int, input().split(" "))))
    casinos.sort(key=lambda t: t[2])
    i = 0
    last = -1
    while i < len(casinos):
        l, r, real = casinos[i]
        if l <= k <= r:
            last = i
        elif last >= 0 and l <= casinos[last][2] <= r:
            last = i
        i += 1
    if last >= 0:
        print(max(k, casinos[last][2]))
    else:
        print(k)
        
