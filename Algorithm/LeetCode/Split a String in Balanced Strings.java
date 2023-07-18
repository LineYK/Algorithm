// 1221. Split a String in Balanced Strings (https://leetcode.com/problems/split-a-string-in-balanced-strings)

class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0, count = 0;

        for (char c : s.toCharArray()) {
            if (c == 'R') count++;
            else count--;
            if(count == 0) ans++;
        }
        return ans;
    }
}