def run() -> int:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort(reverse=True)    

    result = 0
    for i in range(n):
        k = max(0, m-i)
        result += k * a[i]
    return result

num_tests = int(input())
for _ in range(num_tests):
    print(run())
