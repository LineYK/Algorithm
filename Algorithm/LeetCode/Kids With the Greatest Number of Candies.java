// 1431. Kids With the Greatest Number of Candies(https://leetcode.com/problems/kids-with-the-greatest-number-of-candies)

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    // O(n) 1ms
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        List<Boolean> ansList = new ArrayList<>();

        for (int candy : candies) {
            max = Math.max(max, candy);
        }

        for (int candy : candies) {
            ansList.add(candy + extraCandies >= max);
        }
        return ansList;
    }

    // Stream 4ms
    public List<Boolean> kidsWithCandies2(int[] candies, int extraCandies) {
        int max = Arrays.stream(candies).max().getAsInt();
        return Arrays.stream(candies)
                    .mapToObj(candy -> candy + extraCandies >= max)
                    .collect(Collectors.toList());
    }
}
