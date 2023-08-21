// N개의 최소공배수

class Solution {
    public int solution(int[] arr) {
        int res = arr[0];
        for (int i = 1; i < arr.length; i++) {
            res = res * arr[i] / gcd(res, arr[i]);
        }

        return res;
    }

    public int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}