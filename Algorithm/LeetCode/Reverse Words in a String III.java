// 557. Reverse Words in a String III (https://leetcode.com/problems/reverse-words-in-a-string-iii)

// 투 포인터
class Solution {
    public String reverseWords(String s) {
        char[] chars = s.toCharArray();

        int start = 0, end;

        for (end = 0; end <= chars.length; end++) {
            if (end == chars.length || chars[end] == ' ') {
                reverse(chars, start, end - 1);
                start = end + 1;
            }
        }

        return new String(chars);
    }

    private void reverse(char[] c, int start, int end) {
        while (start < end) {
            char tmp = c[end];
            c[end] = c[start];
            c[start] = tmp;
            start++;
            end--;
        }
    }
}