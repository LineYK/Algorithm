// 크기가 작은 부분문자열 (https://school.programmers.co.kr/learn/courses/30/lessons/147355)

import java.util.*;
import java.util.stream.LongStream;

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        List<String> strList = new ArrayList<>();

        for (int i = 0; i <= t.length() - p.length(); i++) {
            strList.add(t.substring(i, p.length() + i));
        }

        Long pNum = Long.parseLong(p);
        for (String str : strList) {
            if (pNum >= Long.parseLong(str))
                answer++;
        }
        return answer;
    }

    public int solution2(String t, String p) {
        int answer = 0;
        Long pNum = Long.parseLong(p);
        for (int i = 0; i <= t.length() - p.length(); i++) {
            Long tNum = Long.parseLong(t.substring(i, p.length() + i));
            if (pNum >= tNum)
                answer++;
        }
        return answer;
    }

    public int solution3(String t, String p) {
        long targetNumber = Long.parseLong(p);
        int targetNumberLength = p.length();

        return (int) LongStream.range(0, t.length() - targetNumberLength + 1)
                .mapToObj(i -> t.substring((int) i, (int) i + targetNumberLength))
                .mapToLong(Long::parseLong)
                .filter(number -> number <= targetNumber)
                .count();
    }
}