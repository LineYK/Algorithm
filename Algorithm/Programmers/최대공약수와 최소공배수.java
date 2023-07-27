// 최대공약수와 최소공배수 (https://school.programmers.co.kr/learn/courses/30/lessons/12940)

class Solution {
    public int[] solution(int n, int m) {
        int[] ans = new int[2];
        ans[0] = gcd(Math.max(n, m), Math.min(n, m));
        ans[1] = n*m/ans[0];
        return ans;
    }
    
    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
}