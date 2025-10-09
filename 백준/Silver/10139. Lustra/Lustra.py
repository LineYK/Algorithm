import sys
input = sys.stdin.readline

T = int(input().strip())
for _ in range(T):
    n = int(input().strip())
    arr = []
    min_w1 = 10**18
    max_w2 = -10**18
    min_h1 = 10**18
    max_h2 = -10**18

    for _i in range(n):
        w1, w2, h1, h2 = map(int, input().split())
        arr.append((w1, w2, h1, h2))
        if w1 < min_w1: min_w1 = w1
        if w2 > max_w2: max_w2 = w2
        if h1 < min_h1: min_h1 = h1
        if h2 > max_h2: max_h2 = h2

    found = False
    for (w1, w2, h1, h2) in arr:
        if w1 == min_w1 and w2 == max_w2 and h1 == min_h1 and h2 == max_h2:
            found = True
            break

    print("TAK" if found else "NIE")
