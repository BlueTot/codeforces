def run():
    k, x = map(int, input().split())
    return (1 << k) * x

num_tests = int(input())
for _ in range(num_tests):
    print(run())
