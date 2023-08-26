// 1528. Shuffle String (https://leetcode.com/problems/shuffle-string)

class Solution {
    public String restoreString(String s, int[] indices) {
        char[] res = new char[indices.length];

        for (int i = 0; i < res.length; i++) {
            res[indices[i]] = s.charAt(i);
        }

        return new String(res);
    }
}