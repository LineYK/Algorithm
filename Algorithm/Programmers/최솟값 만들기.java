// 최솟값 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12941)

import java.util.*;

class Solution {

    // 테스트는 통과 했으나 효율성 테스트에서 안됨
    public int solution(int []A, int []B) {
        int sum = 0;
        List<Integer> listA = new ArrayList<>();
        List<Integer> listB = new ArrayList<>();
        
        for (int a : A) listA.add(a);
        for (int b : B) listB.add(b);

        while(!listA.isEmpty()){
            int max = Collections.max(listA);
            int min = Collections.min(listB);
            sum += max*min;
            listA.remove(Integer.valueOf(max));
            listB.remove(Integer.valueOf(min));
        }
        return sum;
    }

    // Array.sort
    public int solution2(int []A, int []B) {
        int sum = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int i = 0, j = B.length-1; i < A.length; i++, j--) {
            sum += A[i]*B[j];
        }
        
        return sum;
    }
}