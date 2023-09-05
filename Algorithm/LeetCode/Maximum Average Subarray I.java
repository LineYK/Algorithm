// 643. Maximum Average Subarray I (https://leetcode.com/problems/maximum-average-subarray-i/)

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int max = Integer.MIN_VALUE;

        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < k + i; j++) {
                sum += nums[j];
            }
            max = Math.max(max, sum);
        }

        return (double) max / k;
    }

    // 슬라이딩 윈도우 알고리즘
    // 일정한 범위를 가지고 있는 것을 유지하면서 이것을 이동(sliding)
    public double findMaxAverage2(int[] nums, int k) {
        long sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        long max = sum;

        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            max = Math.max(max, sum);
        }

        return max / 1.0 / k;
    }
}
