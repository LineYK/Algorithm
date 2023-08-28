// 2520. Count the Digits That Divide a Number (https://leetcode.com/problems/count-the-digits-that-divide-a-number)

class Solution {
    public int countDigits(int num) {
        int cnt = 0;
        int div = num;
        while(div!=0) {
            if(num%(div%10)==0) cnt++;
            div/=10;
        }
        return cnt;
    }
}