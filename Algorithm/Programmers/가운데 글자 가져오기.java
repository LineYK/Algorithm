// 가운데 글자 가져오기 (https://school.programmers.co.kr/learn/courses/30/lessons/12903)

class Solution {
    public String solution(String s) {
        String ans = "";
        int len = s.length();
        if(len % 2 == 1) ans = String.valueOf(s.charAt(len/2));
        else ans = new StringBuilder().append(s.charAt(len/2 -1)).append(s.charAt(len/2)).toString();
        return ans;
    }
}