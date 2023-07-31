// 2798. Number of Employees Who Met the Target (https://leetcode.com/problems/number-of-employees-who-met-the-target/)

import java.util.Arrays;

class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int ans = 0;
        for (int h : hours) 
            if (h >= target) ans++;

        return ans;
    }

    public int numberOfEmployeesWhoMetTarget2(int[] hours, int target) {
        return (int) Arrays.stream(hours).filter(e -> e >= target).count();
    }
}