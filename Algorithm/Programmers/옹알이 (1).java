// 옹알이 (1) (https://school.programmers.co.kr/learn/courses/30/lessons/120956)

class Solution {
    public int solution(String[] babbling) {
        String[] canBabs = { "aya", "ye", "woo", "ma" };
        int cnt = 0;
        for (String bab : babbling) {
            for (String cb : canBabs)
                bab = bab.replaceAll(cb, "!");
            bab = bab.replaceAll("!", "");
            if (bab.equals(""))
                cnt++;
        }
        return cnt;
    }

    public int solution2(String[] babbling) {
        int answer = 0;
        for (int i = 0; i < babbling.length; i++) {
            if (babbling[i].matches("^(aya(?!aya)|ye(?!ye)|woo(?!woo)|ma(?!ma))+$")) {
                answer++;
            }
        }
        return answer;
    }
}