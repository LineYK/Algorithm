// 2011. Final Value of Variable After Performing Operations(https://leetcode.com/problems/final-value-of-variable-after-performing-operations)

class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (String value : operations) {
            if (value.equals("++X")  || value.equals("X++")) ans++;
            else ans--;
        }
        return ans;
    }

    public int finalValueAfterOperations2(String[] operations) {
        int ans = 0;
        for (String value : operations) {
            if (value.charAt(1) == '+') ans++;
            else ans--;
        }
        return ans;
    }
}