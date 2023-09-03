// 1491. Average Salary Excluding the Minimum and Maximum Salary (https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

class Solution {
    public double average(int[] salary) {
        int max = salary[0], min = salary[0];
        for (int i = 1; i < salary.length; i++) {
            max = Math.max(max, salary[i]);
            min = Math.min(min, salary[i]);
        }
        double sum = 0;
        int cnt = 0;
        for (int s : salary) {
            if (s != max && s != min) {
                cnt++;
                sum += s;
            }
        }

        return sum/cnt;
    }
}