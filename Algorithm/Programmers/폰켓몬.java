// 폰켓몬 (https://school.programmers.co.kr/learn/courses/30/lessons/1845)

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] nums) {
        Set<Integer> mons = new HashSet<>();

        for (int num : nums)
            mons.add(num);

        return nums.length / 2 <= mons.size() ? nums.length / 2 : mons.size();
    }

    public int solution2(int[] nums) {
        return Arrays.stream(nums)
                .boxed()
                .collect(Collectors.collectingAndThen(Collectors.toSet(),
                        phonekemons -> Integer.min(phonekemons.size(), nums.length / 2)));
    }
}