import sys

def add_binary(a: str, b: str) -> str:
    i, j = len(a)-1, len(b)-1
    carry = 0
    res = []
    while i >= 0 or j >= 0 or carry:
        da = int(a[i]) if i >= 0 else 0
        db = int(b[j]) if j >= 0 else 0
        s = da + db + carry
        res.append(str(s & 1))
        carry = s >> 1
        i -= 1; j -= 1
    return ''.join(reversed(res))

def main():
    n = sys.stdin.readline().strip()
    shifted = n + "0000"
    ans = add_binary(shifted, n)
    print(ans)

if __name__ == "__main__":
    main()