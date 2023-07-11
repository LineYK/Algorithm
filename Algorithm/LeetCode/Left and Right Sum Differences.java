// 2574. Left and Right Sum Differences (https://leetcode.com/problems/left-and-right-sum-differences)

import java.util.stream.IntStream;

class Solution {
    public int[] leftRightDifference(int[] nums) {
        int[] left = leftSum(nums);
        int[] right = rightSum(nums);
        
        return IntStream.range(0, nums.length).map(i -> Math.abs(left[i] - right[i])).toArray();
    }

    public int[] leftSum(int[] nums) {
        int[] sums = new int[nums.length];
        int temp = 0;
        for(int i = 0; i < nums.length; i++) {
            sums[i] = temp; 
            temp += nums[i];
        }
        return sums;
    }

    public int[] rightSum(int[] nums) {
        int[] sums = new int[nums.length];
        int temp = 0;
        for(int i = nums.length-1; i >= 0; i--) {
            sums[i] = temp; 
            temp += nums[i];
        }
        return sums;
    }

    public int[] leftRightDifference2(int[] nums) {
        int leftSum = 0;
        int rightSum = 0;
        
        for(int num : nums) rightSum += num;
        for(int i = 0; i < nums.length; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            nums[i] = Math.abs((leftSum - nums[i]) - rightSum);
        }
        return nums;
    }
}