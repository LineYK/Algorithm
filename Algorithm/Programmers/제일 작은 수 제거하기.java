// 제일 작은 수 제거하기 (https://school.programmers.co.kr/learn/courses/30/lessons/12935)

import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        if (arr.length == 1) return new int[]{-1};
        int i = 0;
        int min = Arrays.stream(arr).min().getAsInt();
        int[] ans = new int[arr.length-1];
        for (int num : arr) 
            if(num != min) ans[i++] = num;
        return ans;
    }
}