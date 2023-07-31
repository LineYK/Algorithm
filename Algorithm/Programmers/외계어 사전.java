// 외계어 사전 (https://school.programmers.co.kr/learn/courses/30/lessons/120869)

class Solution {
    public int solution(String[] spell, String[] dic) {
        for (String d : dic){
            int cnt = spell.length;
            for (String s : spell) {
                if(d.contains(s)) cnt--;
            }
            if (cnt == 0) return 1;
        }
        return 2;
    }
}