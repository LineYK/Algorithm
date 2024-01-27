/*
576. 경계를 벗어난 경로

공이 있는 m×n 격자가 있습니다. 공은 처음에 [시작 행, 시작 열] 위치에 있습니다. 
공을 그리드에서 인접한 네 개의 셀 중 하나로 이동할 수 있습니다(그리드 경계를 넘어 그리드 밖으로 이동할 수도 있음). 
공에 최대 최대 이동 횟수까지만 적용할 수 있습니다.

다섯 개의 정수 m, n, maxMove, startRow, startColumn이 주어지면 공을 그리드 경계 밖으로 이동하는 경로의 수를 반환합니다. 답이 매우 클 수 있으므로 모듈로 10^9 + 7을 반환합니다.


예제 1:
입력: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

예제 2:
입력: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

제약 조건:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/

class Solution {
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        int[][] dp = new int[m][n];
        int[] X = {0, 0, -1, 1};
        int[] Y = {-1, 1, 0, 0};
        
        dp[startRow][startColumn] = 1;
        
        for(int i = 0; i < maxMove; i++){
          int[][] temp = new int[m][n];
          for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
              for (int j = 0; j < 4; j++) {
                int x = r + X[j];
                int y = c + Y[j];
                if (x < 0 || x >= m || y < 0 || y >= n) res = (res + dp[r][c]) % 1000000007;
                else temp[x][y] = (temp[x][y] + dp[r][c]) % 1000000007;
              }
            }
          }
          dp = temp;
	      }
	      return res;
    }
}