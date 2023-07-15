// 나누어 떨어지는 숫자 배열 (https://school.programmers.co.kr/learn/courses/30/lessons/12910)

import java.util.Arrays;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] ans = Arrays.stream(arr).filter(e -> e % divisor == 0).toArray();
        if (ans.length == 0) ans = new int[]{-1};
        Arrays.sort(ans);
        return ans;
    }
}