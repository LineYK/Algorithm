/*
1074. 대상에 합산되는 하위 행렬 수

행렬과 목표가 주어졌을 때, 
목표에 합이 되는 비어 있지 않은 행렬의 개수를 반환합니다.

행렬 x1, y1, x2, y2는 x1 <= x <= x2, y1 <= y <= y2를 
갖는 모든 셀의 집합 matrix[x][y]입니다.

두 행렬 (x1, y1, x2, y2)과 (x1', y1', x2', y2')는 
서로 다른 좌표가 있는 경우(예: x1 != x1') 서로 다른 행렬이 됩니다.


예제 1:
입력: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
설명: 설명: 0만 포함하는 4개의 1x1 행렬을 반환합니다.

예제 2:
입력: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
설명: 설명 두 개의 1x2 행렬과 두 개의 2x1 행렬, 그리고 두 개의 2x2 행렬을 더한 값입니다.

예제 3:
입력: 행렬 = [[904]], 대상 = 0
Output: 0

 
제약 조건:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/

class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int cnt = 0;
        int row = matrix.length;
        int col = matrix[0].length + 1;
        int[][] sum = new int[row][col];

        for (int i = 0; i < row; i++) 
            for(int j = 1; j < col; j++)
                sum[i][j] = sum[i][j-1] + matrix[i][j-1];

        
        for (int i = 0; i < col; i++) {
            for (int j = i + 1; j < col; j++) {
                int temp = 0;

                Map<Integer, Integer> map = new HashMap<>();

                map.put(0, 1);
                for (int k = 0; k < row; k++) {
                    temp += sum[k][j] - sum[k][i];
                    if (map.containsKey(temp - target)) cnt += map.get(temp - target);
                    map.put(temp, map.getOrDefault(temp, 0) + 1);
                }
            }
        }

        return cnt;
    }
}