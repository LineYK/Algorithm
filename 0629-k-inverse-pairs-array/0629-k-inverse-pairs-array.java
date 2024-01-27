/*
629. K 역쌍 배열

정수 배열 nums의 경우, 
역쌍은 0 <= i < j < nums.length 및 nums[i] > nums[j]인 정수 [i, j]의 쌍입니다.

두 개의 정수 n과 k가 주어졌을 때, 
정확히 k개의 역쌍이 있는 1에서 n까지의 숫자로 구성된 서로 다른 배열의 수를 반환합니다. 
답이 커질 수 있으므로 모듈로 10^9 + 7을 반환합니다.

예제 1:
입력: n = 3, k = 0
Output: 1
설명: 1부터 3까지의 숫자로 구성된 배열 [1,2,3]만 정확히 0개의 역쌍을 가집니다.

예제 2:
입력: n = 3, k = 1
Output: 2
설명: 배열 [1,3,2]와 [2,1,3]은 정확히 1개의 역쌍을 가집니다.
 

제약 조건:
    1 <= n <= 1000
    0 <= k <= 1000
*/

class Solution {
    public int kInversePairs(int n, int k) {
        if (k > n*(n-1)/2 || k < 0) return 0;
        if (k == n*(n-1)/2 || k == 0) return 1;
        
        long[][] dp = new long[n+1][k+1];

        dp[2][0] = 1;
        dp[2][1] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= Math.min(k, i * (i-1)/2); j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) 
                    dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j] + 1000000007) % 1000000007;
            }
        }
        return (int) dp[n][k];
    }
}