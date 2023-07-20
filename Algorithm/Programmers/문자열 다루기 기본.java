// 문자열 다루기 기본 (https://school.programmers.co.kr/learn/courses/30/lessons/12918)

class Solution {
    public boolean solution(String s) {
        if (s.length() != 4 && s.length() != 6) return false;
        try {
            int a = Integer.parseInt(s);
        } catch(Exception e){
            return false;
        }
        return true;
    }

      public boolean solution2(String s) {
        if (s.length() == 4 || s.length() == 6) return s.matches("(^[0-9]*$)");
        return false;
  }
}