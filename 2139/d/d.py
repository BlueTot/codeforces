def run():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        for i in range(l, r-1):
            if a[i] > a[i+2]:
                print("NO")
                break
        else:
            print("YES")



num_tests = int(input())
for _ in range(num_tests):
    run()
