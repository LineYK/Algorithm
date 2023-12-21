/*
1637. 점을 포함하지 않는 두 점 사이의 가장 넓은 수직 영역
Medium

2D 평면에 점[i] = [xi, yi]인 n개의 점이 주어졌을 때, 두 점 사이의 가장 넓은 수직 면적을 구하여 그 안에 점이 없도록 반환합니다.

수직 영역은 y축을 따라 무한히 확장되는 고정 너비(즉, 무한 높이)의 영역입니다. 가장 넓은 수직 영역은 최대 너비를 가진 영역입니다.

수직 영역의 가장자리에 있는 점은 영역에 포함된 것으로 간주되지 않습니다.

예 1:
입력: points = [[8,7],[9,9],[7,4],[9,7]]
출력: 1
설명: 설명: 빨간색과 파란색 영역이 모두 최적입니다.

예 2:
입력: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3
 

제약 조건:

n == points.length
2 <= n <= 10^5
points[i].length == 2
0 <= xi, yi <= 10^9
*/

class Solution {
    public int maxWidthOfVerticalArea(int[][] points){
        
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0])); 
        int max_width = 0; 
        for (int i = 1; i < points.length; i++) {
            int width = points[i][0] - points[i - 1][0]; 
            max_width = Math.max(max_width, width);
        } 
        return max_width; 
    }      
}