// 1359. Count All Valid Pickup and Delivery Options (https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options)

// 2n!/2^n 조합
class Solution {
    public int countOrders(int n) {
        long res = 1;

        for (int i = 2; i <= 2 * n; i++) {
            res *= i;
            if (i % 2 == 0)
                res /= 2;
            res %= 1000000007;
        }

        return (int) res;
    }
}

// DP
class Solution2 {
    private int mod = (int) Math.pow(10, 9) + 7;
    long[] dp = new long[501];

    public int countOrders(int n) {
        dp[1] = 1;
        dp[2] = 6;
        for (int i = 3; i <= n; i++) {
            int spaceCount = (i - 1) * 2 + 1;
            long val = (spaceCount) * (spaceCount + 1) / 2;
            dp[i] = (dp[i - 1] * val) % mod;
        }
        return (int) dp[n];
    }
}
