// 음양 더하기 (https://school.programmers.co.kr/learn/courses/30/lessons/76501)

class Solution {
    // O(n)
    public int solution(int[] absolutes, boolean[] signs) {
        int ans = 0;
        for (int i = 0; i < absolutes.length; i++)
            if(signs[i]) ans += absolutes[i];
            else ans-= absolutes[i];
        
        return ans;
    }
}