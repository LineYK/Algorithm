// 약수의 개수와 덧셈 (https://school.programmers.co.kr/learn/courses/30/lessons/77884)

class Solution {
    // O(n^2)
    public int solution(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int cnt = countDivisor(i);
            if (cnt % 2 == 1) ans-= i;
            else ans+= i;
        }
        return ans;
    }
    public int countDivisor(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++)
            if(num%i == 0) count++;
        
        return count;
    }

    // O(n)
    public int solution2(int left, int right) {
        int answer = 0;
        for (int i=left;i<=right;i++) {
            if (i % Math.sqrt(i) == 0) answer -= i;
            else answer += i;
        }
        return answer;
    }
}