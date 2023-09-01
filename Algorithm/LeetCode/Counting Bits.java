package LeetCode;

// 338.Counting Bits (https://leetcode.com/problems/counting-bits/)

import java.util.stream.IntStream;

class Solution {
    public int[] countBits(int n) {
        return IntStream.rangeClosed(0, n).map(i -> Integer.bitCount(i)).toArray();
    }

    public int[] countBits2(int n) {
        int[] res = new int[n + 1];
        for (int i = 1; i <= n; i++)
            res[i] = res[i >> 1] + (i & 1);

        return res;
    }
}