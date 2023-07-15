// 없는 숫자 더하기 (https://school.programmers.co.kr/learn/courses/30/lessons/86051)

import java.util.*;

class Solution {
    public int solution(int[] numbers) {
        return 45 - Arrays.stream(numbers).sum();
    }
}