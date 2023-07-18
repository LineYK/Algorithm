// 1828. Queries on Number of Points Inside a Circle (https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)

class Solution {

    // O(n^2)
    public int[] countPoints(int[][] points, int[][] queries) {
        int[] ans = new int[queries.length];
        int i = 0;
        for(int[] query : queries) {
            int count = 0;
            for (int[] point : points){
                int x = point[0] - query[0];
                int y = point[1] - query[1];

                // query 원의 중심으로 부터 좌표 길이를 피타코라스로 구한 후 길이와 반지름의 길이 보다 작으면 안에 있음
                if(x*x + y*y <= query[2]*query[2]) count++;
            }
            ans[i++] = count;
        }
        return ans;
    }
}
