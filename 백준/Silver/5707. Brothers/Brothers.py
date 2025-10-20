import sys
input = sys.stdin.readline

while True:
    line = input().split()
    if not line:
        line = input().split()
    N, R, C, K = map(int, line)
    if N == 0 and R == 0 and C == 0 and K == 0:
        break

    grid = [list(map(int, input().split())) for _ in range(R)]

    dirs = [(-1,0),(1,0),(0,-1),(0,1)]

    for _ in range(K):
        nxt = [row[:] for row in grid] 
        for i in range(R):
            for j in range(C):
                target = (grid[i][j] - 1) % N
                conquered = False
                for dx, dy in dirs:
                    ni, nj = i + dx, j + dy
                    if 0 <= ni < R and 0 <= nj < C:
                        if grid[ni][nj] == target:
                            nxt[i][j] = target
                            break
        grid = nxt

    for row in grid:
        print(" ".join(map(str, row)))
