/*
645. 세트 불일치

원래 1부터 n까지의 모든 숫자를 포함하는 정수 집합 s가 있는데, 
불행히도 어떤 오류로 인해 s의 숫자 중 하나가 집합의 다른 숫자와 중복되어 한 숫자가 반복되고 다른 숫자가 손실되었습니다.

오류 후 이 집합의 데이터 상태를 나타내는 정수 배열 n이 주어집니다.

두 번 발생한 숫자와 누락된 숫자를 찾아 배열의 형태로 반환합니다.

예제 1:
입력: nums = [1,2,2,4]
Output: [2,3]

예제 2:
입력: nums = [1,1]
Output: [1,2]
 

제약 조건:
2 <= nums.length <= 10^4
1 <= nums[i] <= 10^4
*/

class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] res = new int[2];
        Set<Integer> set = new HashSet<>();
        
        for (int num : nums) {
            if(!set.add(num)) {
                res[0] = num;
                res[1] = num+1;
            }
        }

        for (int i = 1; i <= nums.length; i++) {
            if (!set.contains(i)) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
}