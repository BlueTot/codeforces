from collections import Counter

def run():
    n = int(input())
    fxs = list(map(int, input().split()))
    new_counter = {}
    i = 1
    for key, count in Counter(fxs).items():
        if count % key != 0:
            return [-1]
        new_counter[key] = []
        while count > 0:
            for _ in range(key):
                new_counter[key].append(i)
            count -= key
            i += 1
    # print(new_counter)
    xs = []
    curr_counter = {}
    for key in fxs:
        xs.append(new_counter[key][curr_counter.get(key, 0)]) 
        curr_counter[key] = curr_counter.get(key, 0) + 1
    return xs

num_tests = int(input())
for _ in range(num_tests):
    print(" ".join(map(str, run())))
