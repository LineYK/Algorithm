// 2500. Delete Greatest Value in Each Row (https://leetcode.com/problems/delete-greatest-value-in-each-row)

import java.util.*;

class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            Arrays.sort(grid[i]);
        }

        for (int k = 0; k < grid[0].length; k++){
            PriorityQueue<Integer> resQ = new PriorityQueue<>((a,b) -> b-a);
            for (int i = 0; i < grid.length; i++){
                resQ.offer(grid[i][k]);
            }
            res += resQ.poll();
        }

        return res;
    }
}

class Solution2 {
    public int deleteGreatestValue(int[][] grid) {
        for(int i=0; i<grid.length; i++)    Arrays.sort(grid[i]);
        int res = 0;
        for(int i=0; i<grid[0].length; i++){
            int max = 0;
            for(int j=0; j<grid.length; j++)    
                max = Math.max(max, grid[j][i]);
            res += max;
        }
        return res;
    }
}