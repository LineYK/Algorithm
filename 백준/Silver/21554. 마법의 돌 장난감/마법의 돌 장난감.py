import sys
input = sys.stdin.readline

def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    ops = []
    for i in range(1, n+1):
        pos_index = a.index(i)
        pos = pos_index + 1
        if pos == i:
            continue
        l = i
        r = pos
        ops.append((l, r))
        a[i-1:pos_index+1] = reversed(a[i-1:pos_index+1])
    if len(ops) > 100:
        print(-1)
        return
    print(len(ops))
    for l, r in ops:
        print(l, r)

if __name__ == "__main__":
    solve()
