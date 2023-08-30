// 2367. Number of Arithmetic Triplets (https://leetcode.com/problems/number-of-arithmetic-triplets)

import java.util.*;

class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int cnt = 0;
        Set<Integer> set = new HashSet<>();
        for (int num: nums) {
            if (set.contains(num-diff) && set.contains(num-2*diff)) cnt++;
            set.add(num);
        }

        return cnt;
    }
}