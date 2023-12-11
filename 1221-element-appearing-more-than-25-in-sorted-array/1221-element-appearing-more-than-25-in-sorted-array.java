/*
1287. 정렬된 배열에서 25% 이상 나타나는 요소

내림차순이 아닌 순서로 정렬된 정수 배열이 주어졌을 때, 배열에 25% 이상 나타나는 정수가 정확히 하나 있으면 해당 정수를 반환합니다.

예제 1:
입력: arr = [1,2,2,6,6,6,6,6,7,10]
Output: 6

예제 2:
입력: arr = [1,1]
Output: 1
 

제약 조건:

1 <= arr.length <= 104
0 <= arr[i] <= 105
*/

class Solution {
    public int findSpecialInteger(int[] arr) {
        int len = arr.length;
        int perLen = arr.length/4;

        int res = -1;

        for (int i = 0; i < len - perLen; i++) {
            res = arr[i];
            if (res == arr[i + perLen]) break;
        }

        return res;
        
    }
}