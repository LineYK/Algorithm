// 피보나치 수 (https://school.programmers.co.kr/learn/courses/30/lessons/12945)

class Solution {
    public int solution(int n) {
        return fib(n);
    }
    public int fib(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        int result = 0;
        for (int i = 2; i <= n; i++){
            result = first + second;
            first = second%1234567;
            second = result%1234567;
        }
        return result%1234567;
    }
}