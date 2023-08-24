// 2433. Find The Original Array of Prefix Xor (https://leetcode.com/problems/find-the-original-array-of-prefix-xor)

class Solution {
    public int[] findArray(int[] pref) {
        int[] res = new int[pref.length];
        int xorNum = pref[0];

        res[0] = pref[0];

        for (int i = 1; i < res.length; i++) {
            res[i] = xorNum ^ pref[i];
            xorNum ^= res[i];
        }

        return res;
    }

    public int[] findArray2(int[] pref) {
        for (int i = pref.length - 1; i > 0; i--)
            pref[i] ^= pref[i - 1];
        return pref;
    }
}