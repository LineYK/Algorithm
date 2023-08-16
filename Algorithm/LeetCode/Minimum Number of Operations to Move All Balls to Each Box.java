// 1769. Minimum Number of Operations to Move All Balls to Each Box (https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

import java.util.*;

class Solution {
    public int[] minOperations(String boxes) {
        int[] res = new int[boxes.length()];

        char[] boxChars = boxes.toCharArray();
        Set<Integer> balls = new HashSet<>();

        for (int i = 0; i < boxChars.length; i++) {
            if (boxChars[i] == '1')
                balls.add(i);
        }

        for (int i = 0; i < res.length; i++) {
            int sum = 0;
            for (int b : balls) {
                sum += Math.abs(i - b);
            }
            res[i] = sum;
        }
        return res;
    }

    public int[] minOperations2(String boxes) {
        int[] res = new int[boxes.length()];

        int ops = 0;
        int cnt = 0;

        for (int i = 0; i < res.length; i++) {
            res[i] += ops;
            cnt += boxes.charAt(i) - '0';
            ops += cnt;
        }

        ops = 0;
        cnt = 0;

        for (int i = res.length - 1; i >= 0; i--) {
            res[i] += ops;
            cnt += boxes.charAt(i) - '0';
            ops += cnt;
        }

        return res;

    }
}