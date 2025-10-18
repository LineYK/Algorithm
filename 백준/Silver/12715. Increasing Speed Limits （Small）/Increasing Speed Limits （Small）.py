import sys
input = sys.stdin.readline
MOD = 10**9 + 7

class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n+1)
    def add(self, idx, val):
        while idx <= self.n:
            self.bit[idx] = (self.bit[idx] + val) % MOD
            idx += idx & -idx
    def sum(self, idx):
        s = 0
        while idx > 0:
            s = (s + self.bit[idx]) % MOD
            idx -= idx & -idx
        return s

def solve_case():
    n, m, X, Y, Z = map(int, input().split())
    A = [int(input().strip()) for _ in range(m)]
    seq = [0]*n
    for i in range(n):
        idx = i % m
        seq[i] = A[idx]
        A[idx] = (X * A[idx] + Y * (i+1)) % Z

    vals = sorted(set(seq))
    rank_map = {v:i+1 for i,v in enumerate(vals)}  

    fw = Fenwick(len(vals))
    ans = 0
    for v in seq:
        r = rank_map[v]
        sum_less = fw.sum(r-1)
        dp = (1 + sum_less) % MOD
        fw.add(r, dp)
        ans = (ans + dp) % MOD
    return ans

def main():
    T = int(input().strip())
    for tc in range(1, T+1):
        res = solve_case()
        print(f"Case #{tc}: {res}")

if __name__ == "__main__":
    main()
