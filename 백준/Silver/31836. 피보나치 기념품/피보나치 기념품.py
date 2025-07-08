def solve(N):
    F = [0] * (N+3)
    F[1], F[2] = 1, 1
    for i in range(3, N+3):
        F[i] = F[i-1] + F[i-2]

    S = F[N+2] - 1

    used = [False] * (N+1)
    if S & 1:
        used[1] = True
        S -= 1

    T = S // 2

    A = []
    for i in range(N, 0, -1):
        if not used[i] and F[i] <= T:
            A.append(i)
            T -= F[i]
            used[i] = True
        if T == 0:
            break

    B = [i for i in range(1, N+1) if not used[i]]

    print(len(A))
    print(*A)
    print(len(B))
    print(*B)


if __name__ == "__main__":
    import sys
    N = int(sys.stdin.readline())
    solve(N)
