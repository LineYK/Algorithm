import sys
input = sys.stdin.readline

def main():
    left = list(input().rstrip())  
    right = []
    m = int(input().strip())

    for _ in range(m):
        parts = input().split()
        cmd = parts[0]
        if cmd == 'L':
            if left:
                right.append(left.pop())
        elif cmd == 'D':
            if right:
                left.append(right.pop())
        elif cmd == 'B':
            if left:
                left.pop()
        else:  # 'P'
            left.append(parts[1])

    print(''.join(left) + ''.join(reversed(right)))

if __name__ == "__main__":
    main()
