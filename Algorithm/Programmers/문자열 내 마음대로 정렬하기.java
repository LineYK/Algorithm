// 문자열 내 마음대로 정렬하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12915)

import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings);
        Arrays.sort(strings, (a, b) -> a.charAt(n) - b.charAt(n));
        return strings;
    }
}

/*
 * 2545. Sort the Students by Their Kth Score (https://leetcode.com/problems/sort-the-students-by-their-kth-score)
 * 위 문제와 유사
 */