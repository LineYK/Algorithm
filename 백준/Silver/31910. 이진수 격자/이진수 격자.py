import sys
input = sys.stdin.readline

def main():
    N = int(input().strip())
    A = [[0]*(N+1)]
    for _ in range(N):
        row = list(map(int, input().split()))
        A.append([0] + row)  

    dp = [[0]*(N+1) for _ in range(N+1)]
    dp[1][1] = A[1][1]

    for j in range(2, N+1):
        dp[1][j] = (dp[1][j-1] << 1) | A[1][j]
    for i in range(2, N+1):
        dp[i][1] = (dp[i-1][1] << 1) | A[i][1]

    for i in range(2, N+1):
        for j in range(2, N+1):
            from_up = dp[i-1][j] << 1
            from_left = dp[i][j-1] << 1
            dp[i][j] = max(from_up, from_left) | A[i][j]

    print(dp[N][N])

if __name__ == "__main__":
    main()