// 1342. Number of Steps to Reduce a Number to Zero (https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero)

class Solution {
    public int numberOfSteps(int num) {
        int cnt = 0;
        while (num > 0) {
            num = num % 2 == 1 ? num - 1 : num / 2;
            cnt++;
        }
        return cnt;
    }

    public int numberOfSteps2(int num) {
        // 앞에는 2를 나눠야 하는 횟수 + 뒤는 홀수 일때 뺄셈하는 횟수
        return Integer.toBinaryString(num).length() - 1 + Integer.bitCount(num);
    }
}