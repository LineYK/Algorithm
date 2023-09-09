// 1572. Matrix Diagonal Sum (https://leetcode.com/problems/matrix-diagonal-sum)

class Solution {
    public int diagonalSum(int[][] mat) {
        int res = 0;


        for (int i = 0; i < mat.length/2; i++) {
            res += mat[i][i] + mat[i][mat.length-1-i];
            res += mat[mat.length-1-i][i] + mat[mat.length-1-i][mat.length-1-i];
        }

        if (mat.length%2 == 1) res+= mat[mat.length/2][mat.length/2];
        
        return res;
    }
}