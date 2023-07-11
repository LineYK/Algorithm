// 약수의 합 (https://school.programmers.co.kr/learn/courses/30/lessons/12928)

import java.util.stream.*;

class Solution {
    public int solution(int n) {
        return IntStream.range(1, n+1).filter(i -> n%i == 0).sum();
    }
}