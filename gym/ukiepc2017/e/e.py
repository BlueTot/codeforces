from math import factorial

def ncr(n, r):
    return factorial(n) / (factorial(r) * factorial(n-r))

def b(n, r, p) -> float:
    return ncr(n,r) * p ** r * (1 - p) ** (n-r)

def prob(n: int, k: int) -> dict[int, float]:

    if n <= 0:
        return {0: 1}

    result = {}
    for i in range(0, n+1):
        p = b(n, i, 0.5)
        print(i, p)
        for j, q in prob(max(k-n, 0), k-n).items():
            result[i+j] = result.get(i+j, 0) +  p * q

    print(n, k, result)
    return result

def avg(pdist: dict[int, float]):
    result = 0
    for i, p in pdist.items():
        result += i * p
    return result

if __name__ in "__main__":
    n, k = list(map(int, input().split()))
    pdist = prob(min(n,k), k)
    print(pdist, avg(pdist))

    # dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
    # for i in range(1, n+1):
    #     for j in range(1, k+1):
    #         dp[i][j] = dp[i-1][j-1] 

            
