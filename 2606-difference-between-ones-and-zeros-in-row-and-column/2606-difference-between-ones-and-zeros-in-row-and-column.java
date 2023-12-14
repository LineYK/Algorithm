/*
2482. 행과 열의 1과 0의 차이점

인덱스가 0인 m x n 이진 행렬 격자가 주어집니다.

다음 절차에 따라 0 인덱스의 m x n 차분 행렬 diff를 생성합니다:

첫째 행에 있는 1의 개수를 onesRowi로 합니다.
j번째 열에 있는 1의 개수를 onesColj로 합니다.
첫 번째 행의 0의 개수를 zerosRowi로 합니다.
j번째 열의 0의 개수를 zerosColj로 합니다.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
행렬 diff를 반환합니다.

 
예 1:
입력: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
설명을 살펴봅니다:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 1 - 2 = 0 
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 - 4 = 4 
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 1 - 2 = 0 
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 - 4 = 4 
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2

예 2:
입력: grid = [[1,1,1],[1,1,1]]
출력 [[5,5,5],[5,5,5]]
설명입니다:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5
 

제약 조건:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
grid[i][j]는 0 또는 1입니다.
*/

class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int[] rows = new int[grid[0].length];
        int[] cols = new int[grid.length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++){
                cols[i] += grid[i][j];
                rows[j] += grid[i][j];
            }
        }

        int[][] diff = new int[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++){
                diff[i][j] = rows[j] * 2 + cols[i] * 2 - grid.length - grid[0].length;
            }
        }

        return diff;
    }
}