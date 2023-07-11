// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers (https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers)

class Solution {
    public int minPartitions(String n) {
        int ans = 0;
        for (int i = 0; i < n.length(); i++) {
            ans = Math.max(ans, Character.getNumericValue(n.charAt(i)));
        }
        return ans;
    }
}