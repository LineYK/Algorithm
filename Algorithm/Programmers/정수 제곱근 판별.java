// 정수 제곱근 판별 (https://school.programmers.co.kr/learn/courses/30/lessons/12934)

class Solution {
    public long solution(long n) {
        long ans = -1;
        double square = Math.sqrt( (double) n );
        if (square % 1 == 0.0) ans = (long) Math.pow(square + 1, 2);
        return ans;
    }
}