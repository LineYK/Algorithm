// 2161. Partition Array According to Given Pivot (https://leetcode.com/problems/partition-array-according-to-given-pivot)

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] res = new int[nums.length];
        int len = nums.length;
        int left = 0, right = len-1;

        for (int i = 0; i < len; i++) {
            if (nums[i] < pivot) res[left++] = nums[i];

            if (nums[len-1-i] > pivot) res[right--] = nums[len-1-i];
        }

        while(left <= right) {
            res[left++] = pivot;
            res[right--] = pivot;
        }

        return res;
    }
}