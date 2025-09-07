def run():
    n = int(input())
    
    def to_trinary(n):
        result = []
        while n > 0:
            result.append(n % 3)
            n //= 3
        return result

    def price(x):
        return 3 ** (x - 1) * (x + 9)

    total = 0
    for i, trit in enumerate(to_trinary(n)):
        total += trit * price(i)

    print(int(total))


num_tests = int(input())
for _ in range(num_tests):
    run()
