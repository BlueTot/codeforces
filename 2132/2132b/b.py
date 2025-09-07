def run():
    n = int(input())
    results = []
    for k in range(len(str(n)), 0, -1):
        pow = 10**k + 1
        if n % pow == 0:
            results.append(n // pow)
    if len(results) == 0:
        print(0)
    else:
        print(len(results))
        print(" ".join(map(str, results)))

num_tests = int(input())
for _ in range(num_tests):
    run()
