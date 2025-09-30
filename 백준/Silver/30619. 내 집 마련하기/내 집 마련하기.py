import sys
input = sys.stdin.readline

def process_query(N, A, L, R):
    H = [i+1 for i in range(N) if L <= A[i] <= R]
    H.sort()
    B = A[:]
    for k, house in enumerate(H):
        B[house-1] = L + k
    return B

def main():
    N = int(input().strip())
    A = list(map(int, input().split()))
    M = int(input().strip())
    for _ in range(M):
        L, R = map(int, input().split())
        B = process_query(N, A, L, R)
        print(" ".join(map(str, B)))

if __name__ == "__main__":
    main()
