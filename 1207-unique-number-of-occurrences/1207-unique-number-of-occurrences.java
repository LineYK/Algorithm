/*1207. 고유 발생 횟수

정수 배열 배열이 주어졌을 때, 
배열에 있는 각 값의 발생 횟수가 고유하면 참을 반환하고 그렇지 않으면 거짓을 반환합니다.


예제 1:
입력: arr = [1,2,2,1,1,3]
출력: true
설명: 값 1에는 3개, 2에는 2개, 3에는 1개가 있습니다. 두 값의 발생 횟수가 같을 수는 없습니다.

예제 2:
입력: arr = [1,2]
출력: false

예 3:
입력: arr = [-3,0,1,-3,1,1,1,1,-3,10,0]
출력: true

제약 조건:
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/


class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int n : arr) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        Set<Integer> set = new HashSet<>();

        for (int cnt : map.values())
            if(!set.add(cnt)) return false;

        return true;
    }
}