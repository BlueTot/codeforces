import random

with open("d2.txt", "w") as f:
    num_tests = 10
    f.write(f"{num_tests}\n")
    for _ in range(num_tests):
        n, k = 5, random.randint(1, 10)
        f.write(f"{n} {k}\n")
        for _ in range(n):
            a = random.randint(1, 10)
            b = random.randint(a, 10)
            c = random.randint(a, b)
            f.write(f"{a} {b} {c}\n")

