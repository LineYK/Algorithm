// 1389. Create Target Array in the Given Order (https://leetcode.com/problems/create-target-array-in-the-given-order)

import java.util.ArrayList;

class Solution {
    // stream O(n)
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> arrList = new ArrayList<>();
        for(int i = 0; i < nums.length; i++)
            arrList.add(index[i], nums[i]);
        
        return arrList.stream().mapToInt(Integer::intValue).toArray();
    }

    // O(n)
    public int[] createTargetArray2(int[] nums, int[] index) {
        ArrayList<Integer> arrList = new ArrayList<>();

        for(int i = 0; i < nums.length; i++)
            arrList.add(index[i], nums[i]);
        
        int[] ans = new int[arrList.size()];

        for(int i = 0; i < ans.length; i++) 
            ans[i] = arrList.get(i);
        
        return ans;
    }
}