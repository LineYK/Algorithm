// 1313. Decompress Run-Length Encoded List(https://leetcode.com/problems/decompress-run-length-encoded-list)

import java.util.*;

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> numsList = new ArrayList<>();

        for (int i = 0; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                numsList.add(nums[i + 1]);
            }
        }

        int[] res = new int[numsList.size()];

        for (int i = 0; i < res.length; i++)
            res[i] = numsList.get(i);

        return res;
    }

    public int[] decompressRLElist2(int[] nums) {
        int length = 0;

        for (int i = 0; i < nums.length; i += 2) {
            length += nums[i];
        }

        int[] result = new int[length];
        int index = 0;

        for (int i = 0; i < nums.length; i += 2) {
            Arrays.fill(result, index, index + nums[i], nums[i + 1]);
            index += nums[i];
        }

        return result;
    }
}