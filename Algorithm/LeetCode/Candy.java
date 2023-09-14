// 135. Candy (https://leetcode.com/problems/candy)

import java.util.Arrays;

class Solution {
    public int candy(int[] ratings) {
        int res = 0;
        int len = ratings.length;
        int[] candies = new int[len];
        Arrays.fill(candies, 1);

        for (int i = 1; i < len; i++) {
          int prev = ratings[i-1];
          int cur = ratings[i];
          if (prev < cur) candies[i] = candies[i - 1] + 1;
        }

        for (int i = len - 2; i >= 0; i--) {
          int cur = ratings[i];
          int next = ratings[i+1]; 
          if (cur > next) candies[i] = Math.max(candies[i+1] + 1, candies[i]);
        }

        for (int candy : candies) res+= candy;

        return res;
    }
}