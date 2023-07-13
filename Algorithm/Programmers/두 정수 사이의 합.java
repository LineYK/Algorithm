// 두 정수 사이의 합 (https://school.programmers.co.kr/learn/courses/30/lessons/12912)

import java.util.stream.*;

class Solution {
    // Stream 1.8ms - 36ms
    public long solution(int a, int b) {
        return LongStream.rangeClosed(Math.min(a, b), Math.max(a, b)).sum();
    }

    // O(1)
    public long solution2(int a, int b) {
        return sumAtoB(Math.min(a, b), Math.max(a, b));
    }
    
    public long sumAtoB(long a, long b) {
        return (b - a + 1) * (a + b) / 2;
    }
}
