num_tests = int(input())
for _ in range(num_tests):
    n = int(input())
    arr = []
    if n % 2 == 0:
        for i in range(n):
            if i % 2 == 0:
                arr.append(-1)
            elif i == n-1:
                arr.append(2)
            else:
                arr.append(3)
    else:
        for i in range(n):
            if i % 2 == 0:
                arr.append(-1)
            else:
                arr.append(3)
    print(" ".join(list(map(str, arr))))
