// 저주의 숫자 3 (https://school.programmers.co.kr/learn/courses/30/lessons/120871)

class Solution {
       public int solution(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            ans++;
            if (ans%3 == 0 || Integer.toString(ans).contains("3")) i--;
        }
        return ans;
    }
}