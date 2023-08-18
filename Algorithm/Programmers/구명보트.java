// 구명보트 (https://school.programmers.co.kr/learn/courses/30/lessons/42885)

import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int res = 0;
        int len = people.length;
        for (int b = 0, s = 0; b + s < len; ) {
            if (people[s] + people[len-1-b] > limit){
                b++;
            } else {
                b++;
                s++;
            }
            res++;
        }       
        return res;
    }
}