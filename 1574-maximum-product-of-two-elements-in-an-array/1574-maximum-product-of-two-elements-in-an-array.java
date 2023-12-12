/*
1464. 배열에서 두 원소의 최대 곱 찾기

정수 n의 배열이 주어졌을 때, 그 배열의 서로 다른 두 인덱스 i와 j를 선택합니다. (nums[i]-1)*(nums[j]-1)의 최대값을 반환합니다.
 

예제 1:

입력: nums = [3,4,5,2]
Output: 12 
설명: 인덱스 i=1 및 j=2(0부터 인덱싱)를 선택하면 최대값, 즉 (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12를 얻을 수 있습니다. 

예 2:

입력: nums = [1,5,4,5]
Output: 16
설명: 인덱스 i=1 및 j=3(0부터 인덱싱)을 선택하면 최대값인 (5-1)*(5-1) = 16을 얻을 수 있습니다.
예 3:

입력: nums = [3,7]
Output: 12
 

제약 조건:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

class Solution {
    public int maxProduct(int[] nums) {
        int len = nums.length;
        Arrays.sort(nums);

        return (nums[len-1] - 1) * (nums[len-2] - 1);
    }
}