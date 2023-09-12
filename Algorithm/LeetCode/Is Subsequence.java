//392. Is Subsequence (https://leetcode.com/problems/is-subsequence)

class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() == 0) return true;

        int sStart = 0, sLen = s.length(); 

        for (int i = 0; i < t.length(); i++){
            if(t.charAt(i) == s.charAt(sStart)){
                sStart++;
            }
            if (sStart == sLen) return true;
        }

        return false;
    }
}