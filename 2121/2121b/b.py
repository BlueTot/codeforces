num_tests = int(input())

def check(n, s):
    for i in range(1, n-1):
        a, b, c = s[:i], s[i:i+1], s[i+1:]
        if b in a + c:
            return "Yes"
    return "No"

for _ in range(num_tests):
    n = int(input())
    s = input()
    print(check(n,s))

    

