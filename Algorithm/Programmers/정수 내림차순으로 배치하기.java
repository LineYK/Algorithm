// 정수 내림차순으로 배치하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12933)

import java.util.*;

class Solution {
    public long solution(long n) {
        char[] chars = Long.toString(n).toCharArray();
        Arrays.sort(chars);
        return Long.parseLong(new StringBuilder().append(chars).reverse().toString());
    }

    public long solution2(long n) {
        return Long.parseLong(String.valueOf(n).chars().mapToObj(ch -> (char) ch)
                .sorted(Comparator.reverseOrder())
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString()
                );
    }
}