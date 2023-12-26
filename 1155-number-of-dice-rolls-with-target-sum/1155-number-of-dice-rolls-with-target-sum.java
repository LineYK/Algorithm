/*
1155. 목표 합계가 있는 주사위 굴림 횟수

n개의 주사위가 있고, 각 주사위의 앞면은 1부터 k까지 번호가 매겨져 있습니다.

세 개의 정수 n, k, 목표가 주어졌을 때, 
주사위를 굴릴 수 있는 방법의 개수(총 개수 k^n 중)를 반환하여 앞면이 있는 숫자의 합이 목표와 같도록 합니다. 
답이 너무 클 수 있으므로 모듈로 10^9 + 7을 반환합니다.

 

예제 1:

입력: n = 1, k = 6, 목표 = 3
Output: 1
설명: 주사위를 던집니다: 앞면이 6개인 주사위 하나를 던집니다.
3의 합을 얻는 방법은 하나뿐입니다.

예제 2:
입력: n = 2, k = 6, 목표 = 7
출력: 6 
설명: 주사위를 던집니다: 각각 앞면이 6개인 주사위 두 개를 던집니다.
1+6, 2+5, 3+4, 4+3, 5+2, 6+1의 6가지 방법으로 7의 합을 얻을 수 있습니다.

예제 3:
입력: n = 30, k = 30, 목표 = 500
Output: 222616187
설명: 답은 10^9 + 7을 나눠서 반환해야 합니다.
 

제약 조건:

1 <= n, k <= 30
1 <= target <= 1000

*/

class Solution {
    final int mod = (int) Math.pow(10, 9) + 7;

    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n + 1][target + 1];

        for (int[] d : dp) 
            Arrays.fill(d, -1);

        return helper(dp, n, k, target);
    }


    int helper(int[][] dp, int n, int k, int target) {
        if (target == 0 && n == 0) return 1;
        if (n == 0 || target <= 0) return 0;

        if (dp[n][target] != -1) 
            return (int) (dp[n][target] % mod);
        int way = 0;
        for (int i = 1; i <= k; i++) {
            way = (way + helper(dp, n - 1, k, target - i)) % mod;
        }
        dp[n][target] = way % mod;
        return dp[n][target];
    }
}