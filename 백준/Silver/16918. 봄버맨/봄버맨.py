import sys
input = sys.stdin.readline

def explode(grid, R, C):
    exploded = [[True]*C for _ in range(R)]  
    dirs = [(0,0),(1,0),(-1,0),(0,1),(0,-1)]
    for i in range(R):
        row = grid[i]
        for j in range(C):
            if row[j] == 'O':
                for dx, dy in dirs:
                    nx, ny = i + dx, j + dy
                    if 0 <= nx < R and 0 <= ny < C:
                        exploded[nx][ny] = False
    res = []
    for i in range(R):
        line = []
        for j in range(C):
            line.append('O' if exploded[i][j] else '.')
        res.append(''.join(line))
    return res

def main():
    R, C, N = map(int, input().split())
    initial = [input().strip() for _ in range(R)]

    if N == 1:
        for row in initial:
            print(row)
        return

    if N % 2 == 0:
        full = 'O' * C
        for _ in range(R):
            print(full)
        return

    state3 = explode(initial, R, C)  
    if N % 4 == 3:
        for row in state3:
            print(row)
        return
    else:
        state5 = explode(state3, R, C)
        for row in state5:
            print(row)
        return

if __name__ == "__main__":
    main()
