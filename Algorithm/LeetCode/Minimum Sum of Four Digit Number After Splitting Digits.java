// 2160. Minimum Sum of Four Digit Number After Splitting Digits (https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits)

import java.util.Arrays;

class Solution {
    public int minimumSum(int num) {
        int n1, n2;
        char[] nums = String.valueOf(num).toCharArray();
        Arrays.sort(nums);
        n1 = Integer.parseInt(new StringBuilder().append(nums[0]).append(nums[2]).toString());
        n2 = Integer.parseInt(new StringBuilder().append(nums[1]).append(nums[3]).toString());
        return n1 + n2;
    }

    public int minimumSum2(int num) {
        int n1, n2;
        int[] nums = new int[4];
        int i = 0;
        while (num > 0) {
            nums[i++] = num % 10;
            num /= 10;
        }
        Arrays.sort(nums);
        n1 = nums[0] * 10 + nums[2];
        n2 = nums[1] * 10 + nums[3];
        return n1 + n2;
    }
}