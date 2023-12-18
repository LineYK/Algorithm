/*
1913. 두 쌍의 최대 상품 차이

두 쌍 (a, b)와 (c, d) 사이의 곱의 차는 (a * b) - (c * d)로 정의됩니다.

- 예를 들어, (5, 6)과 (2, 7)의 곱의 차는 (5 * 6) - (2 * 7) = 16입니다.

정수 배열 nums가 주어졌을 때, (nums[w], nums[x]) 쌍과 (nums[y], nums[z]) 쌍 사이의 곱의 차가 최대가 되도록 4개의 서로 다른 인덱스 w, x, y, z를 선택합니다.


이러한 최대 곱의 차이를 반환합니다.

예 1:
입력: nums = [5,6,2,7,4]
Output: 34
설명: 첫 번째 쌍(6, 7)에 인덱스 1과 3을, 두 번째 쌍(2, 4)에 인덱스 2와 4를 선택할 수 있습니다.
곱의 차이는 (6 * 7) - (2 * 4) = 34입니다.

예 2:
입력: nums = [4,2,5,9,7,4,8]
Output: 64
설명: 첫 번째 쌍(9, 8)에 인덱스 3과 6을, 두 번째 쌍(2, 4)에 인덱스 1과 5를 선택할 수 있습니다.
곱의 차이는 (9 * 8) - (2 * 4) = 64입니다.
 
제약 조건:
4 <= nums.length <= 104
1 <= nums[i] <= 104
*/

class Solution {
    public int maxProductDifference(int[] nums) {
        int len = nums.length;
        
        Arrays.sort(nums);

        return (nums[len -1] * nums[len - 2]) - (nums[0] * nums[1]);
    }
}