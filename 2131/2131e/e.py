num_tests = int(input())

def test(a: list[int], b: list[int]) -> bool:
    for i in range(n):
        if a[i] != b[i]:
            if i == 0:
                if a[i] ^ a[i+1] != b[i]:
                    return False
            elif i == n-1:
                if a[i] ^ a[i-1] != b[i]:
                    return False
            else:
                if a[i] ^ a[i+1] != b[i] and a[i] ^ a[i-1] != b[i]:
                    return False
    return True



for _ in range(num_tests):
    n = int(input())
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    print("YES" if test(a, b) else "NO")
