// 문자열 내 p와 y의 개수 (https://school.programmers.co.kr/learn/courses/30/lessons/12916)

class Solution {
    // O(N) 0.03ms
    boolean solution(String s) {
        int count = 0;
        s = s.toUpperCase();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'P') count++;
            else if(s.charAt(i) == 'Y') count--;
        }
        return count == 0;
    }

    // stream 1.8ms
    boolean solution2(String s) {
        s = s.toUpperCase();

        return s.chars().filter(e -> e == 'P').count() == s.chars().filter(e -> e == 'Y').count();
    }
}