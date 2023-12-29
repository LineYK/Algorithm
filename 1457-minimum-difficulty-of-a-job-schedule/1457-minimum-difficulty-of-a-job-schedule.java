/*
1335. 작업 일정의 최소 난이도
어려움 \U0001f622

일 단위로 작업 목록을 예약하려고 합니다. 작업은 종속적입니다(즉, i번째 작업을 수행하려면 0 <= j < i번째 작업을 수행하려면 모든 작업 j를 완료해야 합니다).

당신은 매일 적어도 하나의 일을 끝내야만 합니다. 취업 일정의 난이도는 그 날의 각각의 일의 난이도의 합입니다. 하루의 난이도는 그 날에 행해진 취업의 최대 난이도입니다.

정수 배열 작업 난이도와 정수 d가 주어집니다. i번째 작업의 난이도는 작업 난이도[i]입니다.

작업 스케줄의 최소 난이도를 반환합니다. 작업 스케줄을 찾을 수 없는 경우 -1을 반환합니다.



예 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
출력 : 7
설명: 첫 번째 5개의 작업을 완료할 수 있습니다. 총 난이도 = 6.
둘째 날, 마지막 작업을 끝낼 수 있습니다. 총 난이도 = 1.
스케줄 난이도 = 6 + 1 = 7

예 2:

Input: jobDifficulty = [9,9,9], d = 4
출력 : -1
설명: 하루에 일을 끝내도 당신은 여전히 자유로운 하루를 가질 것입니다. 당신은 주어진 일들의 일정을 찾을 수 없습니다.

예 3:

Input: jobDifficulty = [1,1,1], d = 3
출력 : 3
설명: 일정은 1일 1개, 총 난이도는 3개입니다.

제약 조건:

1 <= 작업 난이도.길이 <= 300
0 <= 직무 난이도 [i] <= 1000
1 < = d < = 10
*/

class Solution {
    int[][] dp;

    public int minDifficulty(int[] jobDifficulty, int d) {
        if (d > jobDifficulty.length) return -1;

        dp = new int[d-1][jobDifficulty.length];
        for (int[] arr : dp)
            Arrays.fill(arr, -1);

        return dfs(jobDifficulty, d-1, 0);
    }

    int dfs(int[] jobDifficulty, int d, int pos) {
        if (d == 0) {
            int max = jobDifficulty[pos];
            for (int i = pos; i < jobDifficulty.length; i++)
                max = Math.max(max, jobDifficulty[i]);
            return max;
        }

        int day = dp.length - d;

        if(dp[day][pos] != -1)
            return dp[day][pos];

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (int i = pos; i < jobDifficulty.length-d; i++) {
            max = Math.max(max, jobDifficulty[i]);
            min = Math.min(min, max + dfs(jobDifficulty, d-1, i+1));
        }
        return dp[day][pos] = min;
    }
}