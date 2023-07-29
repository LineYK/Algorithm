// 숫자의 표현 (https://school.programmers.co.kr/learn/courses/30/lessons/12924)

class Solution {
    // O(n^2)
    public int solution(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = i; j <= n; j++) {
                sum += j;
                if (sum == n) {
                    cnt++;
                    break;
                } else if (sum > n)
                    break;
            }
        }
        return cnt;
    }

    // O(n) 
    // 주어진 자연수를 연속된 자연수의 합으로 표현하는 방법의 수는 주어진 수의 홀수 약수의 개수와 같다
    public int solution2(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i += 2)
            if (n % i == 0)
                cnt++;
        return cnt;
    }
}