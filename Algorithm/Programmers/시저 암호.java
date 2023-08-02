// 시저 암호

class Solution {
    public String solution(String s, int n) {
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();

        for (char c : chars) {
            if (c == ' ') {
                sb.append(c);
                continue;
            }
            int ascii = (int) c;
            if (ascii >= 97) {
                if (ascii + n > 122)
                    ascii -= 26;
            } else if (ascii > 65 && ascii + n > 90) {
                ascii -= 26;
            }
            sb.append((char) (ascii + n));
        }
        return sb.toString();
    }

    public String solution2(String s, int n) {
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();

        for (char c : chars) {
            if (Character.isLowerCase(c)) {
                c = (char) ((c - 'a' + n) % 26 + 'a');
            } else if (Character.isUpperCase(c)) {
                c = (char) ((c - 'A' + n) % 26 + 'A');
            }
            sb.append(c);
        }
        return sb.toString();
    }
}