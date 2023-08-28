// 2610. Convert an Array Into a 2D Array With Conditions (https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions)

import java.util.*;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int[] count = new int[nums.length+1];
        
        for (int num : nums) {
            if (res.size() < ++count[num]){
                res.add(new ArrayList<>());
            }
            res.get(count[num]-1).add(num);
        }
        return res;
    }
}