// 287. Find the Duplicate Number (https://leetcode.com/problems/find-the-duplicate-number)

import java.util.*;

class Solution {
    public int findDuplicate(int[] nums) {
        int res = 0;
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if(!set.add(nums[i])){
                res = nums[i];
                break;
            }
        }
        return res;
    }
}

// 플로이드의 토끼와 거북이 알고리즘(Floyd's Tortoise and Hare Algorithm)
class Solution2 {
    public int findDuplicate(int[] nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
}