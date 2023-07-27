// 같은 숫자는 싫어 (https://school.programmers.co.kr/learn/courses/30/lessons/12906)

import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> ansList = new ArrayList<>();
        int temp = -1;
        for(int num : arr) 
            if (temp != num) {
                ansList.add(num);
                temp = num;
            }
        
        int[] ans = new int[ansList.size()];
        for(int i = 0; i < ans.length; i++)
            ans[i] = ansList.get(i);
        
        return ans;
    }
}