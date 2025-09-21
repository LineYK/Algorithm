import sys
input = sys.stdin.readline

def is_valid_solution(n, grid):
    lit = [[False]*n for _ in range(n)]
    dirs = [(-1,0),(1,0),(0,-1),(0,1)]
    
    for i in range(n):
        for j in range(n):
            if grid[i][j] == '?':
                lit[i][j] = True
                for dx, dy in dirs:
                    x, y = i + dx, j + dy
                    while 0 <= x < n and 0 <= y < n:
                        cell = grid[x][y]
                        if cell != '.' and cell != '?':
                            break
                        if cell == '?':
                            return False
                        lit[x][y] = True
                        x += dx
                        y += dy

    for i in range(n):
        for j in range(n):
            if grid[i][j] == '.' or grid[i][j] == '?':
                if not lit[i][j]:
                    return False

    for i in range(n):
        for j in range(n):
            if grid[i][j] in '01234':
                need = int(grid[i][j])
                cnt = 0
                for dx, dy in dirs:
                    x, y = i + dx, j + dy
                    if 0 <= x < n and 0 <= y < n and grid[x][y] == '?':
                        cnt += 1
                if cnt != need:
                    return False

    return True

def main():
    n = int(input().strip())
    grid = [list(input().strip()) for _ in range(n)]
    print(1 if is_valid_solution(n, grid) else 0)

if __name__ == "__main__":
    main()
