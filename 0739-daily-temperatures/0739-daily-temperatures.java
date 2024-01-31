/*
739. 일일 기온

일별 온도를 나타내는 정수 온도 배열이 주어졌을 때, 
answer[i]가 더 따뜻한 온도를 얻기 위해 i째 날 이후 기다려야 하는 일수가 되도록 배열의 답을 반환합니다. 
이것이 가능한 미래 날짜가 없으면 대신 answer[i] == 0을 유지합니다.

예제 1:
입력: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

예 2:
입력: temperatures = [30,40,50,60]
Output: [1,1,1,0]

예 3:
입력: temperatures = [30,60,90]
Output: [1,1,0]
 
제약 조건:
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
*/
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] res = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int idx = stack.pop();
                res[idx] = i - idx;
            }
            stack.push(i);
        }

        return res;
    }
}