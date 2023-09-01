// 238. Product of Array Except Self (https://leetcode.com/problems/product-of-array-except-self)

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        int mul = 1, zeroCnt = 0, index = 0;

        for (int i = 0; i < res.length; i++) {
            if (nums[i] == 0) {
                index = i;
                zeroCnt++;
                continue;
            }
            mul *= nums[i];
        }

        if (zeroCnt > 1) {
            return res;
        } else if (zeroCnt == 1) {
            res[index] = mul;
        } else {
            for (int i = 0; i < res.length; i++) {
                res[i] = mul/nums[i];
            }
        }

        return res;
    }
}