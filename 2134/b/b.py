from math import gcd

def run() -> list[int]:
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    for div in range(2, max(3, k * k)):
        result = []
        for i in range(n):
            if a[i] % gcd(k, div) != 0:
                break
            for m in range(0, 100):
                if (a[i] + k * m) % div == 0:
                    result.append(a[i] + k * m)
                    break
        if len(result) < n:
            continue
        return result

    return [0]


num_tests = int(input())
for _ in range(num_tests):
    print(" ".join(map(str, run())))



