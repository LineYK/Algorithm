// 가장 가까운 같은 글자 (https://school.programmers.co.kr/learn/courses/30/lessons/142086)

import java.util.*;

class Solution {
    public int[] solution(String s) {
        char[] chars = s.toCharArray();
        int[] res = new int[chars.length];

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < chars.length; i++) {
            if (!map.containsKey(chars[i])) {
                res[i] = -1;
                map.put(chars[i], i);
                continue;
            }
            res[i] = i - map.get(chars[i]);
            map.put(chars[i], i);
        }

        return res;
    }

    public int[] solution2(String s) {
        char[] chars = s.toCharArray();
        int[] res = new int[chars.length];

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < chars.length; i++) {
            res[i] = i - map.getOrDefault(chars[i], i + 1);
            map.put(chars[i], i);
        }

        return res;
    }
}