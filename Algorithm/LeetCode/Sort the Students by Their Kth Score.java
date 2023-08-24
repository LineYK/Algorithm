// 2545. Sort the Students by Their Kth Score (https://leetcode.com/problems/sort-the-students-by-their-kth-score)

import java.util.*;

class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Integer[] targets = new Integer[score.length];
        int[][] res = new int[score.length][score[0].length];
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < score.length; i++) {
            targets[i] = score[i][k];
            map.put(targets[i], i);
        }

        Arrays.sort(targets, (i1, i2) -> i2 - i1);

        for (int i = 0; i < score.length; i++) {
            res[i] = score[map.get(targets[i])];
        }

        return res;
    }

    public int[][] sortTheStudents2(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}