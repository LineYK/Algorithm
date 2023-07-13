// 1281. Subtract the Product and Sum of Digits of an Integer (https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/)

class Solution {
    public int subtractProductAndSum(int n) {
        String num = Integer.toString(n);
        int product = 1;
        int sum = 0;
        for (int i = 0; i < num.length(); i++) {
            int dit = num.charAt(i) - '0';
            product *= dit;
            sum += dit;
        }

        return product - sum;
    }
}