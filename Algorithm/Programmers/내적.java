// 내적 (https://school.programmers.co.kr/learn/courses/30/lessons/70128)

import java.util.stream.IntStream;

class Solution {
    public int solution(int[] a, int[] b) {
        int ans = 0;
        for(int i = 0; i < a.length; i++) ans += a[i]*b[i];
        return ans;
    }

    public int solution2(int[] a, int[] b) {
        return IntStream.range(0, a.length).map(e -> a[e]*b[e]).sum();
    }
}