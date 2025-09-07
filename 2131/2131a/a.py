num_tests = int(input())
for _ in range(num_tests):
    n = int(input())
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    
    # 8 + 7 + 4 = 19
    # 3 + 3 = 6
    total = 0
    for i in range(n):
        if a[i] > b[i]:
            total += a[i] - b[i]
    print(total + 1)
