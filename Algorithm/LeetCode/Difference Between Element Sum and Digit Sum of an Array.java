// 2535. Difference Between Element Sum and Digit Sum of an Array (https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array)

class Solution {
    public int differenceOfSum(int[] nums) {
        int res = 0;
        for (int num : nums) {
            if (num >= 10) {
                res += num;
                while(num != 0) {
                    res -= num%10;
                    num /= 10;
                }
            }
        }
        return res;
    }
}
