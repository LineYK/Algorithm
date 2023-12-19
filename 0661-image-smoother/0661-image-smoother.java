/*
661. 더 부드러운 이미지

이미지 스무더는 셀과 주변 8개 셀의 평균(즉, 파란색 스무더의 9개 셀의 평균)을 
반올림하여 이미지의 각 셀에 적용할 수 있는 3 x 3 크기의 필터입니다. 
셀의 주변 셀 중 하나 이상이 존재하지 않는 경우 평균에 포함하지 않습니다
(즉, 빨간색 스무더에 있는 4개 셀의 평균).

이미지의 회색조를 나타내는 m x n 정수 행렬 img가 주어지면, 
이미지의 각 셀에 스무더를 적용한 후 이미지를 반환합니다.

예제 1:
입력: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
설명입니다:
(0,0), (0,2), (2,0), (2,2) 점의 경우: floor(3/4) = floor(0.75) = 0입니다.
(0,1), (1,0), (1,2), (2,1) 점의 경우: floor(5/6) = floor(0.83333333) = 0
점 (1,1)의 경우: floor(8/9) = floor(0.88888889) = 0

예제 2:
입력: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
설명입니다:
(0,0), (0,2), (2,0), (2,2) 점의 경우: floor((100+200+200+50)/4) = floor(137.5) = 137입니다.
(0,1), (1,0), (1,2), (2,1) 점의 경우: floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
점 (1,1)의 경우: floor((50+200+200+200+200+100+100+100)/9) = floor(138.888889) = 138
 

제약 조건:
m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255
*/

class Solution {
    public int[][] imageSmoother(int[][] img) {
        int res[][] = new int[img.length][img[0].length];
        for(int i = 0; i < img.length; i++) {
            for(int j = 0; j < img[0].length; j++) {
                res[i][j] = smoothen(img, i, j);
            }
        }
        return res;
    }

    int smoothen(int[][] img, int x, int y) {
        int m = img.length; 
        int n = img[0].length;
        int sum = 0;
        int count = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                sum += img[nx][ny];
                count++;
            }
        }

        return sum/count;
    }
}
