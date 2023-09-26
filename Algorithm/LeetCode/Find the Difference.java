// 389. Find the Difference (https://leetcode.com/problems/find-the-difference)

import java.util.*;

class Solution {
    public char findTheDifference(String s, String t) {
        char[] arr1 = s.toCharArray();
        char[] arr2 = t.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) return arr2[i];
        }

        return arr2[arr2.length-1];
    }
}