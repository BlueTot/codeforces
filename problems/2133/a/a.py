def run():
    n = int(input())
    num_gears = list(map(int, input().split()))
    return len(set(num_gears)) < len(num_gears)

num_tests = int(input())
for _ in range(num_tests):
    if run():
        print("YES")
    else:
        print("NO")
