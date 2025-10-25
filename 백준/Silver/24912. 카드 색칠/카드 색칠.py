import sys
input = sys.stdin.readline

def solve():
    n = int(input().strip())
    a = list(map(int, input().split()))
    for i in range(n-1):
        if a[i] != 0 and a[i] == a[i+1]:
            print(-1)
            return

    i = 0
    while i < n:
        if a[i] != 0:
            i += 1
            continue
        j = i
        while j < n and a[j] == 0:
            j += 1
        right = a[j] if j < n else 0

        for p in range(i, j):
            prev = a[p-1] if p-1 >= 0 else 0
            avoid = right if p == j-1 and right != 0 else 0
            for c in (1,2,3):
                if (prev == 0 or c != prev) and (avoid == 0 or c != avoid):
                    a[p] = c
                    break
        i = j

    for k in range(n-1):
        if a[k] == a[k+1]:
            print(-1)
            return

    print(" ".join(map(str, a)))

if __name__ == "__main__":
    solve()
