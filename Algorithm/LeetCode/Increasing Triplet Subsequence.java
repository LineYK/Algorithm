// 334. Increasing Triplet Subsequence (https://leetcode.com/problems/increasing-triplet-subsequence)

class Solution {
    public boolean increasingTriplet(int[] nums) {
        int min = Integer.MAX_VALUE, cur = 0, max = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length - 2; i++) {
            min = Math.min(min, nums[i]);
            cur = nums[i + 1];
            max = Math.max(max, nums[nums.length - 1 - i]);
            if (min < cur && cur < max)
                return true;
        }
        if (nums.length >= 3)
            if (nums[0] < nums[1] && nums[1] < nums[2])
                return true;
        return false;
    }
}

class Solution2 {
    public boolean increasingTriplet(int[] nums) {
        int min = Integer.MAX_VALUE, mid = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num <= min) {
                min = num;
            } else if (num <= mid) {
                mid = num;
            } else
                return true;
        }
        return false;
    }
}