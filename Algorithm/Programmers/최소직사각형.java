// 최소직사각형 (https://school.programmers.co.kr/learn/courses/30/lessons/86491)

class Solution {
    public int solution(int[][] sizes) {
        int maxW = 0, maxL = 0;
        
        for (int[] size : sizes) {
            int curMax = Math.max(size[0], size[1]);
            int curMin = Math.min(size[0], size[1]);
            
            maxW = Math.max(maxW, curMax);
            maxL = Math.max(maxL, curMin);
        }
        return maxW * maxL;
    }
}