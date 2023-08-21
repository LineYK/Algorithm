// 두 개 뽑아서 더하기 (https://school.programmers.co.kr/learn/courses/30/lessons/68644)

import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> nums = new HashSet<>();

        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++)
                nums.add(numbers[i] + numbers[j]);
        }
        int[] res = nums.stream().mapToInt(Integer::valueOf).toArray();
        Arrays.sort(res);
        return res;
    }

    public int[] solution2(int[] numbers) {
        Set<Integer> nums = new HashSet<>();

        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++)
                nums.add(numbers[i] + numbers[j]);
        }

        return nums.stream().sorted().mapToInt(Integer::valueOf).toArray();
    }
}