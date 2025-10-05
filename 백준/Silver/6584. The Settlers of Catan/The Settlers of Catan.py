import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def solve_case(n, m, edges):
    adj = [[] for _ in range(n)]
    for eid, (u, v) in enumerate(edges):
        adj[u].append((v, eid))
        adj[v].append((u, eid))

    best = 0

    def dfs(u, used_mask, length):
        nonlocal best
        if length > best:
            best = length
        for v, eid in adj[u]:
            if not (used_mask >> eid) & 1:
                dfs(v, used_mask | (1 << eid), length + 1)

    for start in range(n):
        dfs(start, 0, 0)

    return best

def main():
    out_lines = []
    while True:
        line = input().split()
        if not line:
            break
        n, m = map(int, line)
        if n == 0 and m == 0:
            break
        edges = []
        for _ in range(m):
            u, v = map(int, input().split())
            edges.append((u, v))
        ans = solve_case(n, m, edges)
        out_lines.append(str(ans))
    print("\n".join(out_lines))

if __name__ == "__main__":
    main()
