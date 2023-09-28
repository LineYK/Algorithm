// 905. Sort Array By Parity (https://leetcode.com/problems/sort-array-by-parity)

// Two Point
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] res = new int[nums.length];

        int left = 0;
        int right = res.length-1;
        for (int num : nums) {
            if (num % 2 == 0) res[left++] = num;
            else res[right--] = num;
        }

        return res;
    }
}

class Solution2 {
    public int[] sortArrayByParity(int[] nums) {
        for (int i = 0, j = 0; j < nums.length; j++){
            if (nums[j] % 2 == 0) {
                int tmp = nums[i];
                nums[i++] = nums[j];
                nums[j] = tmp;
            }
        }
        return nums;
    }
}