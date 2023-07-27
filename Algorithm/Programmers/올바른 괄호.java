// 올바른 괄호 (https://school.programmers.co.kr/learn/courses/30/lessons/12909)

class Solution {
    boolean solution(String s) {
        int cnt = 0;
        if (s.charAt(0) != '(' || s.charAt(s.length()-1) != ')') return false;
        for(char c : s.toCharArray()){
            if (c == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        
        return cnt == 0;
    }
}