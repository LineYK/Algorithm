// 짝지어 제거하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12973)

import java.util.*;

class Solution {
    public int solution(String s) {
        char[] chars = s.toCharArray();
        Stack<Character> stack = new Stack<>();

        for (char c : chars) {
            if (!stack.isEmpty() && stack.peek() == c)
                stack.pop();
            else
                stack.push(c);
        }

        return stack.isEmpty() ? 1 : 0;
    }
}