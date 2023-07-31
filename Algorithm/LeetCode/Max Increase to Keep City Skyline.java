// 807. Max Increase to Keep City Skyline (https://leetcode.com/problems/max-increase-to-keep-city-skyline/)

class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int len = grid.length;
        int[] maxRow = new int[len];
        int[] maxCol = new int[len];

        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++){
                maxRow[i] = Math.max(maxRow[i], grid[i][j]);
                maxCol[j] = Math.max(maxCol[j], grid[i][j]);
            }

        int res = 0;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++){
                res += Math.min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        
        return res;
    }
}

/* 푸는 데 어려웠음 */