/*
867. 행렬 전치

2D 정수 배열 행렬이 주어지면 행렬의 순서를 반환합니다.

행렬의 전치란 행렬의 행과 열 인덱스를 바꾸어 행렬의 주 대각선을 뒤집은 것을 말합니다.

예제 1:

입력: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

예 2:

입력: matrix = [[1,2,3],[4,5,6]]]
Output: [[1,4],[2,5],[3,6]]
 

제약 조건:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
*/

class Solution {
    public int[][] transpose(int[][] matrix) {
        int[][] res = new int[matrix[0].length][matrix.length];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j< matrix[0].length; j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }


}