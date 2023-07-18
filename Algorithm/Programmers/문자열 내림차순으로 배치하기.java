// 문자열 내림차순으로 배치하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12917)

import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.*;

class Solution {
    public String solution(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new StringBuilder(String.valueOf(chars)).reverse().toString();
    }

    public String solution2(String s) {
        return Stream.of(s.split("")).sorted(Comparator.reverseOrder()).collect(Collectors.joining());
    }
}