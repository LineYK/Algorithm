// 콜라츠 추측 (https://school.programmers.co.kr/learn/courses/30/lessons/12943)

class Solution {
    public int solution(long num) {
        int count;
        for(count = 0; count < 500; count++) {
            if(num == 1) return count;
            if(num%2 == 0) num /= 2;
            else num = num * 3 + 1;
        }
        return -1;
    }
}