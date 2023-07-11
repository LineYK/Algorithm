// 1365. How Many Numbers Are Smaller Than the Current Number (https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number)

import java.util.*;

class Solution {

    // O(n^2) 15ms
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ans = new int[nums.length];
        for(int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = 0; j < nums.length; j++) 
                if (nums[i] > nums[j]) count++;
            ans[i] = count;
        }
        return ans;
    }
    // O(n) 4ms
    public int[] smallerNumbersThanCurrent2(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] copy = nums.clone();

        Arrays.sort(copy);

        for (int i = 0; i < nums.length; i++) 
            map.putIfAbsent(copy[i], i);

        for (int i = 0; i < nums.length; i++) 
            copy[i] = map.get(nums[i]);

        return copy;
    }
}