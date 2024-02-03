public class Solution {
    public boolean isMatch(String s, String p) {
        if (s.isEmpty()) {
            if (p.isEmpty()) return true;
            if (p.length() >= 2 && p.charAt(1) == '*') return isMatch(s, p.substring(2));
            return false;
        }

        if (p.isEmpty()) return false;
        
        if (p.length() >= 2 && p.charAt(1) == '*') {
            if (isSame(s.charAt(0), p.charAt(0))) {
                return isMatch(s.substring(1), p);
            } else {
                return isMatch(s, p.substring(2));
            }
        } else {
            if (isSame(s.charAt(0), p.charAt(0)) return isMatch(s.substring(1), p.substring(1));
        }
        
        return false;
    }
    
    private boolean isSame(char s, char p) {
        if (s == p || p == '.') return true;
        return false;
    }
}