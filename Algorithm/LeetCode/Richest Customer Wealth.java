// 1672. Richest Customer Wealth(https://leetcode.com/problems/richest-customer-wealth)

import java.util.Arrays;

class Solution {
    // O(n^2) + stream 4ms
    public int maximumWealth(int[][] accounts) {
        int[] sums = new int[accounts.length];

        for(int i = 0; i < accounts.length; i++) {
            for(int j = 0; j < accounts[i].length; j++) sums[i] += accounts[i][j];
        }

        return Arrays.stream(sums).max().getAsInt();
    }

    // stream 4ms
    public int maximumWealth2(int[][] accounts) {
        return Arrays.stream(accounts).mapToInt(account -> Arrays.stream(account).sum()).max().getAsInt();
    }

    // O(n^2) 0ms
    public int maximumWealth3(int[][] accounts) {
        int max = 0;

        for(int i = 0; i < accounts.length; i++) {
            int sum = 0;
            for(int j = 0; j < accounts[i].length; j++) sum += accounts[i][j];

            max = Math.max(max, sum);
        }

        return max;
    }
}

/** mapToInt
 * 
 * 
 */