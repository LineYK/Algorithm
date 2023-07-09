// 자릿수 더하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12931)

import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        String temp = Integer.toString(n);
        for (int i = 0; i < temp.length(); i++) {
            answer += temp.charAt(i) - '0';
        }
        return answer;
    }
}