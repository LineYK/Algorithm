import sys

MAXN = 1000000

def sieve(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5)+1):
        if is_prime[i]:
            step = i
            start = i*i
            is_prime[start:n+1:step] = [False] * (((n - start)//step) + 1)
    return is_prime

def main():
    data = sys.stdin.read().strip().split()
    nums = list(map(int, data))
    # build sieve
    is_prime = sieve(MAXN)

    out_lines = []
    memo = {}

    for n in nums:
        if n == 0:
            break
        if n in memo:
            out_lines.append(memo[n])
            continue

        found = False
        for a in range(3, n//2 + 1, 2):
            if is_prime[a] and is_prime[n - a]:
                s = f"{n} = {a} + {n-a}"
                out_lines.append(s)
                memo[n] = s
                found = True
                break
        if not found:
            s = "Goldbach's conjecture is wrong."
            out_lines.append(s)
            memo[n] = s

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()
