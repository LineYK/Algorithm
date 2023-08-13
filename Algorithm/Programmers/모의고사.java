// 모의고사 (https://school.programmers.co.kr/learn/courses/30/lessons/42840)

import java.util.ArrayList;
import java.util.List;

class Solution {

    public int[] solution(int[] answers) {
        int[] s1 = new int[] { 1, 2, 3, 4, 5 };
        int[] s2 = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] s3 = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

        int[] counts = new int[3];

        for (int i = 0; i < answers.length; i++) {
            if (s1[i % s1.length] == answers[i])
                counts[0]++;
            if (s2[i % s2.length] == answers[i])
                counts[1]++;
            if (s3[i % s3.length] == answers[i])
                counts[2]++;
        }

        int index = 0;

        for (int i = 0, max = 0; i < counts.length; i++) {
            if (max < counts[i]) {
                max = counts[i];
                index = i;
            }
        }

        List<Integer> resList = new ArrayList<>();

        if (index == 0) {
            resList.add(1);
            if (counts[index] == counts[index + 1])
                resList.add(2);
            if (counts[index] == counts[index + 2])
                resList.add(3);
        }
        if (index == 1) {
            resList.add(2);
            if (counts[index] == counts[index + 1])
                resList.add(3);
        }

        if (index == 2) {
            resList.add(3);
        }

        return resList.stream().mapToInt(Integer::intValue).toArray();
    }

    // 위보다 1ms 느림
    public int[] solution2(int[] answers) {
        int[] s1 = new int[] { 1, 2, 3, 4, 5 };
        int[] s2 = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] s3 = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

        int[] counts = new int[3];

        for (int i = 0; i < answers.length; i++) {
            if (s1[i % s1.length] == answers[i])
                counts[0]++;
            if (s2[i % s2.length] == answers[i])
                counts[1]++;
            if (s3[i % s3.length] == answers[i])
                counts[2]++;
        }

        int maxCnt = Math.max(counts[0], Math.max(counts[1], counts[2]));

        List<Integer> resList = new ArrayList<>();

        if(maxCnt == counts[0]) resList.add(1);
        if(maxCnt == counts[1]) resList.add(2);
        if(maxCnt == counts[2]) resList.add(3);

        return resList.stream().mapToInt(Integer::intValue).toArray();
    }
}