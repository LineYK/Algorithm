// 1137. N-th Tribonacci Number (https://leetcode.com/problems/n-th-tribonacci-number)

class Solution {
    public int tribonacci(int n) {
        if (n == 0)
            return 0;
        else if (n <= 2)
            return 1;

        int[] arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for (int i = 3; i < arr.length; i++) {
            arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
        }

        return arr[n];
    }

    public int tribonacci2(int n) {
        if (n < 2)
            return n;
        int a = 0, b = 1, c = 1, d;
        while (n-- > 2) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
}