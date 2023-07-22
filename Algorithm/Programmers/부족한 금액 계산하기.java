// 부족한 금액 계산하기 (https://school.programmers.co.kr/learn/courses/30/lessons/82612)

import java.util.stream.*;

class Solution {
    // O(n) stream
    public long solution(int price, int money, int count) {
        Long ans = LongStream.rangeClosed(1, count).map(e -> price * e).sum() - money;
        return ans < 0 ? 0 : ans;
    }
    // O(1) 등차수열 합
    public long solution2(long price, int money, int count) {
        return Math.max(price * (count * (1 + count) / 2) - money, 0);
    }
}