/*
2610. 배열을 조건이 있는 2D 배열로 변환하기

정수 배열 n이 주어집니다. 다음 조건을 만족하는 숫자로 2D 배열을 만들어야 합니다:

2D 배열은 배열 nums의 요소만 포함해야 합니다.
2D 배열의 각 행은 고유한 정수를 포함해야 합니다.
2D 배열의 행 수는 최소여야 합니다.
결과 배열을 반환합니다. 정답이 여러 개 있으면 그 중 하나를 반환합니다.

2D 배열은 각 행의 요소 수가 다를 수 있다는 점에 유의하세요.

 
예제 1:
입력: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
설명: 다음과 같은 행을 포함하는 2D 배열을 만들 수 있습니다:
- 1,3,4,2
- 1,3
- 1
숫자의 모든 요소가 사용되었고, 2D 배열의 각 행은 고유한 정수를 포함하므로 정답입니다.
유효한 배열에는 3개 미만의 행을 가질 수 없음을 알 수 있습니다.

예제 2:
입력: nums = [1,2,3,4]
Output: [[4,3,2,1]]
설명: 배열의 모든 요소는 고유하므로 2D 배열의 첫 번째 행에 모든 요소를 유지할 수 있습니다.
 

제약 조건:
1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int[] count = new int[nums.length+1];
        
        for (int num : nums) {
            if (res.size() < ++count[num]){
                res.add(new ArrayList<>());
            }
            res.get(count[num]-1).add(num);
        }
        return res;
    }
}