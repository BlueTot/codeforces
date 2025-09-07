def run() -> list[int]:
    n = int(input())
    p = list(map(int, input().split()))

    q = [n - v + 1 for v in p]
    # print([p[i] + q[i] for i in range(n)])
    return q

num_tests = int(input())
for _ in range(num_tests):
    print(" ".join(map(str, run())))
