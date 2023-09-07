// 2006. Count Number of Pairs With Absolute Difference K

import java.util.*;

class Solution {
    public int countKDifference(int[] nums, int k) {
        int cnt = 0;

        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i+1; j < nums.length; j++){
                if (Math.abs(nums[i] - nums[j]) == k) cnt++;
            }
        }

        return cnt;
    }
}

class Solution2 {
    public int countKDifference(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int cnt = 0;

        for (int num : nums) {
            cnt += map.getOrDefault(num-k, 0);
            cnt += map.getOrDefault(num+k, 0);

            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        return cnt;
    }
}