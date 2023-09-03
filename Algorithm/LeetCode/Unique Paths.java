// 62. Unique Paths (https://leetcode.com/problems/unique-paths)

// DP
// 큰 문제를 작은 하위 문제들로 분해하고, 각 하위 문제의 결과를 저장해 놓아서 중복 계산을 피하면서 문제를 효율적으로 해결
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    grid[i][j] = 1;
                else
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
}