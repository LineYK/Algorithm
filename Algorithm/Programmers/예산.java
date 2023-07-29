// 예산 (https://school.programmers.co.kr/learn/courses/30/lessons/12982)

import java.util.Arrays;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = d.length;
        int sum = Arrays.stream(d).sum();
        Arrays.sort(d);
        for (int i = d.length - 1; i >= 0; i--, answer--) {
            if (sum <= budget)
                break;
            sum -= d[i];
        }
        return answer;
    }

    public int solution2(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);
        for (int i = 0; i < d.length; i++) {
            budget -= d[i];
            if (budget < 0)
                break;
            answer++;
        }
        return answer;
    }
}