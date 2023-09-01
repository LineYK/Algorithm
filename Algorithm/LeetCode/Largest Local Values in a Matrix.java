// 2373. Largest Local Values in a Matrix

class Solution {
    public int[][] largestLocal(int[][] grid) {
        int len = grid.length;
        int[][] res = new int[len-2][len-2];

        for (int i = 0; i < res.length; i++) {
            for (int j = 0; j < res.length; j++){
                for (int row = i; row < i+3; row++){
                    for (int col = j; col < j+3; col++) {
                        res[i][j] = Math.max(grid[row][col], res[i][j]);
                    }
                }
            }
        }

        return res;
    }
}