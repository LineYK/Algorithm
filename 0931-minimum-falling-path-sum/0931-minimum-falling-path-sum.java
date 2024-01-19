/*

931. 최소 하강 경로 합계

정수 행렬의 n x n 배열이 주어졌을 때, 

행렬을 통과하는 모든 하강 경로의 최소 합을 반환합니다.

하강 경로는 첫 번째 행의 임의의 요소에서 시작하여 

다음 행의 바로 아래 또는 대각선 왼쪽/오른쪽에 있는 요소를 선택합니다. 

구체적으로, (행, 열) 위치에서 다음 요소는 (행 + 1, 열 - 1), (행 + 1, 열) 또는 (행 + 1, 열 + 1)이 될 것입니다.

예시 1:

입력: matrix = [[2,1,3],[6,5,4],[7,8,9]]

Output: 13

설명: 설명: 아래와 같이 최소 합이 있는 두 개의 하강 경로가 있습니다.

예제 2:

입력: matrix = [[-19,57],[-40,-5]]

Output: -59

설명: 설명: 최소 합이 있는 하강 경로를 표시합니다.

제약 조건:

n == matrix.length == matrix[i].length

1 <= n <= 100

-100 <= matrix[i][j] <= 100

*/

class Solution {

    public int minFallingPathSum(int[][] matrix) {

        int n = matrix.length;
        int[][] dp = new int[n][n];
        int min = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(j == 0) dp[i][j] = Math.min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                else if (j == n-1) dp[i][j] = Math.min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                else dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i-1][j+1])) + matrix[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            min = Math.min(min, dp[n-1][i]);
        }
        
        return min;
   }
}