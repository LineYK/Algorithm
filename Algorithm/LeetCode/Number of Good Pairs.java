// 1512. Number of Good Pairs(https://leetcode.com/problems/number-of-good-pairs)

import java.util.HashMap;

class Solution {
    // O(n^2)
    public int numIdenticalPairs(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for(int j = i+1; j < nums.length; j++) 
                if(nums[i] == nums[j] && i < j) count++;
        }
        return count;
    }

    // O(n)
    public int numIdenticalPairs2(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int ans = 0;

        for(int num: nums) {
            int count = map.getOrDefault(num, 0);
            ans+= count;
            map.put(num, count+1);
        }
        return ans;
    }

}