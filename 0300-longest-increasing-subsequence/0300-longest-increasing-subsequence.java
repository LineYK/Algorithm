/*
300. 가장 긴 증가 연속

정수 배열의 숫자가 주어지면, 엄격하게 증가하는 가장 긴 수열의 길이를 반환합니다. 
서브 시퀀스

예제 1:
입력: nums = [10,9,2,5,3,7,101,18]
Output: 4
설명: 설명: 가장 긴 증가 수열은 [2,3,7,101]이므로 길이는 4입니다.

예제 2:
입력: nums = [0,1,0,3,2,3]
Output: 4


예제 3:
입력: nums = [7,7,7,7,7,7,7]
Output: 1
 

제약 조건:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/

class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;

        int[] dp = new int[len];

        for (int i = 0; i < len; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j])
                     dp[i] = (dp[i] < dp[j]+1) ? dp[j] + 1 : dp[i];
            }
        }

        int max = 0;
        
        for (int n : dp) {
            max = Math.max(max, n);
        }

        return max+1;
    }
}