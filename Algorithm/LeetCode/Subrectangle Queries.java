// 1476. Subrectangle Queries(https://leetcode.com/problems/subrectangle-queries)

class SubrectangleQueries {
    int[][] rectangle;

    public SubrectangleQueries(int[][] rectangle) {
        this.rectangle = rectangle;
    }

    // O(N^2)
    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) rectangle[i][j] = newValue;
        }
    }
    
    // O(1)
    public int getValue(int row, int col) {
        return rectangle[row][col];
    }
}

/**
 * SubrectangleQuery 객체가 인스턴스화되고 다음과 같이 호출됩니다:
 * SubrectangleQueries obj = new SubrectangleQueries(rectangle);
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj.getValue(row,col);
 */

 /**
  * 생성자에서 this 미사용으로 2ms 더 빠름
  */
 class SubrectangleQueries2 {
    int[][] rect;

    public SubrectangleQueries2(int[][] rectangle) {
        rect = rectangle;
    }
    
    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) rect[i][j] = newValue;
        }
    }
    
    public int getValue(int row, int col) {
        return rect[row][col];
    }
}
