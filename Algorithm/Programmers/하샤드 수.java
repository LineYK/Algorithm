// 하샤드 수 (https://school.programmers.co.kr/learn/courses/30/lessons/12947)

class Solution {

    // O(n) 0.02ms
    public boolean solution(int x) {
        int sum = 0, num = x;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return x % sum == 0;
    }

    // Stream 1.8ms
    public boolean solution2(int x) {
        int sum = Integer.toString(x).chars().map(c -> c - '0').sum();
        return x % sum == 0;
    }
}