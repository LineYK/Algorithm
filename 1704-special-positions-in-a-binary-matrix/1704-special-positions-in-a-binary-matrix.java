/*
1582. 이진 행렬의 특수 위치

m x n 이진 행렬 mat이 주어졌을 때, mat의 특수 위치의 개수를 반환합니다.

mat[i][j] == 1이고 행 i와 열 j의 다른 모든 요소가 0이면 (행과 열이 0 인덱싱되어 있음) 위치(i, j)를 특수 위치라고 부릅니다.

예제 1:
입력: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
설명: mat[1][2] == 1이고 행 1과 열 2의 다른 모든 요소가 0이기 때문에 (1, 2)는 특수한 위치입니다.

예제 2:
입력: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
설명: (0, 0), (1, 1) 및 (2, 2)는 특수 위치입니다.
 

제약 조건:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j]는 0 또는 1입니다.
*/

class Solution {
    public int numSpecial(int[][] mat) {
        int[] rows = new int[mat.length];
        int[] cols = new int[mat[0].length];

        for(int i = 0; i < rows.length; i++) {
            for (int j = 0; j < cols.length; j++){
                if(mat[i][j] == 1) {
                    rows[i]++; 
                    cols[j]++;
                }
            }
        }

        int res = 0;

        for(int i = 0; i < rows.length; i++) {
            for (int j = 0; j < cols.length; j++){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) 
                    res++;
            }
        }

        return res;
    }
}