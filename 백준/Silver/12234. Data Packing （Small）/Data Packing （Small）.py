import sys
input = sys.stdin.readline

T = int(input().strip())
for tc in range(1, T+1):
    line = input().split()
    while len(line) < 2:
        line = input().split()
    N, X = map(int, line)
    sizes = list(map(int, input().split()))
    sizes.sort()
    l, r = 0, N-1
    ans = 0
    while l <= r:
        if l == r:
            ans += 1
            break
        if sizes[l] + sizes[r] <= X:
            l += 1
            r -= 1
            ans += 1
        else:
            r -= 1
            ans += 1
    print(f"Case #{tc}: {ans}")
