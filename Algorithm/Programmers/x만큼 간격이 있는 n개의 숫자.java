// x만큼 간격이 있는 n개의 숫자(https://school.programmers.co.kr/learn/courses/30/lessons/12954)

import java.util.stream.LongStream;

class Solution {
    public long[] solution(int x, int n) {
        return LongStream.range(1, n+1).map(i -> i * x).toArray();
    }
}