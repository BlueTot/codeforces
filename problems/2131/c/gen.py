from random import randint

with open("c3.txt", "w") as f:
    f.write("10\n")
    for _ in range(10):
        f.write(f"10 {randint(1, 5)}\n")
        f.write(" ".join([str(randint(1, 20)) for _ in range(10)]) + "\n")
        f.write(" ".join([str(randint(1, 20)) for _ in range(10)]) + "\n")
    
