// 258. Add Digits (https://leetcode.com/problems/add-digits)

class Solution {
    public int addDigits(int num) {
        int sum = 0;

        String s = Integer.toString(num);

        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
        }

        if (sum < 10) 
            return sum;
        else 
            return addDigits(sum);
        
    }
}