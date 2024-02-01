/*
446. 산술 슬라이스 II - 수열

정수 배열 nums가 주어졌을 때, 
nums의 모든 산술 수열의 개수를 반환합니다.

숫자의 수열은 적어도 세 개의 요소로 구성되어 있고 연속된 두 요소의 차이가 같으면 산술이라고 합니다.

예를 들어 [1, 3, 5, 7, 9], [7, 7, 7, 7], [3, -1, -5, -9]는 산술 수열입니다.
예를 들어 [1, 1, 2, 5, 7]은 산술 수열이 아닙니다.
배열의 부분열은 배열의 일부 요소를 제거하여 형성할 수 있는 시퀀스입니다(아예 없을 수도 있음).

예를 들어, [2,5,10]은 [1,2,1,2,4,1,5,10]의 시퀀스입니다.
테스트 케이스는 답이 32비트 정수에 맞도록 생성됩니다.

 
예제 1:
입력: nums = [2,4,6,8,10]
Output: 7
설명: 모든 산술 후속 조각은 다음과 같습니다:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

예제 2:
입력: nums = [7,7,7,7,7]
Output: 16
설명: 이 배열의 모든 후속은 산술입니다.
*/

class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int res = 0;
        Map<Long, Integer>[] dp = new Map[nums.length];

        for (int i = 0; i < nums.length; i++)
            dp[i] = new HashMap<>();
        
        for (int i = 1; i < nums.length; i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long) nums[i] - (long) nums[j];
                int cnt = dp[j].getOrDefault(diff, 0);
                dp[i].put(diff, dp[i].getOrDefault(diff, 0) + cnt + 1);
                res += cnt;
            }
        }
        return res;
    }
}