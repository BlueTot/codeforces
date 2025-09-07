num_tests = int(input())
for _ in range(num_tests):
    print("".join(sorted(input(), reverse=True)))
