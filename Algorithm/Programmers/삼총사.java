// 삼총사 (https://school.programmers.co.kr/learn/courses/30/lessons/131705)

class Solution {
    public int solution(int[] num) {
        int ans = 0;
        int len = num.length;
        
        for(int i = 0; i < len; i++)
            for(int j = i+1; j < len; j++)
                for(int k = j +1; k < len; k++)
                    if (num[i] + num[j] + num[k] == 0) ans++;
        
        
        return ans;
    }
}