// H-Index (https://school.programmers.co.kr/learn/courses/30/lessons/42747)

import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int res = 0;
        Integer[] arr = Arrays.stream(citations).boxed().toArray(Integer[]::new);

        Arrays.sort(arr, (a, b) -> b - a);

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > res) {
                res++;
            } else
                break;
        }
        return res;
    }

    public int solution2(int[] citations) {
        Arrays.sort(citations);

        int max = 0;
        for (int i = citations.length - 1; i > -1; i--) {
            int min = (int) Math.min(citations[i], citations.length - i);
            if (max < min)
                max = min;
        }

        return max;
    }
}