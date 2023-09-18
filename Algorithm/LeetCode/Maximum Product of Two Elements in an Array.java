// 1464. Maximum Product of Two Elements in an Array (https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array)

import java.util.*;

class Solution {
    public int maxProduct(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        Arrays.stream(nums).forEach(e -> pq.offer(e));
        return (pq.poll()-1) * (pq.poll()-1);
    }
}

class Solution2 {
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        return (nums[nums.length-1]-1)*(nums[nums.length-2]-1);
    }
}