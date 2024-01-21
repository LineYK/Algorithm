/*
907. 서브배열 최소값의 합계

정수 배열 배열이 주어졌을 때, 
배열의 모든 (인접한) 하위 배열에 걸쳐 있는 b의 범위가 최소(b)의 합을 구합니다. 
답이 클 수 있으므로 10^9 + 7의 나머지로 답을 반환합니다.

예제 1:
입력: arr = [3,1,2,4]
Output: 17
설명: 
하위 배열은 [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4] 입니다. 
최소값은 3, 1, 2, 4, 1, 1, 1, 2, 1, 1, 1입니다.
합계는 17입니다.

예 2:
입력: arr = [11,81,94,43,3]
Output: 444

제약 조건:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4
*/

class Solution {
    public int sumSubarrayMins(int[] arr) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] dp = new int[arr.length+1];
        int res = 0;

        stack.push(-1);

        for (int i = 0; i < arr.length; i++) {
            while (stack.peek() != -1 && arr[i] < arr[stack.peek()]) {
                stack.pop();
            }
            dp[i+1] = (dp[stack.peek()+1] + (i - stack.peek()) * arr[i]) % ((int)Math.pow(10, 9) + 7);
            stack.push(i);
            res += dp[i+1];
            res %= (int)Math.pow(10, 9) + 7;
        }

        return res;
    }
}