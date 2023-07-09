// 1480. Running Sum of 1d Array (https://leetcode.com/problems/running-sum-of-1d-array/description/)

import java.util.stream.IntStream;

class Solution {

    // O(n) 0ms
    public int[] runningSum(int[] nums) {
        int temp = 0;
        int[] res = new int[nums.length];
        
        for (int i = 0; i < nums.length; i++) {
            temp += nums[i];
            res[i] = temp;
        }

        return res;
    }

    // stream 4ms
    public int[] runningSum2(int[] nums) {
        return IntStream.range(0, nums.length).map(i -> i == 0 ? nums[i]:(nums[i]+=nums[i-1])).toArray();
    }
}

/** IntStream.range
 * 
 * 
 */