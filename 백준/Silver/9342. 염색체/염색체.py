import sys
import re

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    pattern = re.compile(r'^[A-F]?A+F+C+[A-F]?$')
    out_lines = []
    for i in range(1, 1 + t):
        s = data[i].strip()
        if pattern.fullmatch(s):
            out_lines.append("Infected!")
        else:
            out_lines.append("Good")
    print("\n".join(out_lines))

if __name__ == "__main__":
    main()