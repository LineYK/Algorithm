// 서울에서 김서방 찾기 (https://school.programmers.co.kr/learn/courses/30/lessons/12919)

import java.util.Arrays;

class Solution {
    // O(n) 8ms
    public String solution(String[] seoul) {
        int index = 0;
        for (int i = 0; i < seoul.length; i++)
            if(seoul[i].equals("Kim")) {
                index = i;
                break;
            }    
        return "김서방은 " + index + "에 있다";
    }

    // List 8ms
    public String solution2(String[] seoul) {
        int index = Arrays.asList(seoul).indexOf("Kim");        
        return "김서방은 "+ index + "에 있다";
    }

    // StringBuilder 사용으로 0.07ms 속도 개선
    public String solutionWithSB(String[] seoul) {
        int index = 0;
        for (int i = 0; i < seoul.length; i++)
            if(seoul[i].equals("Kim")) {
                index = i;
                break;
            }       
        return new StringBuilder("김서방은 ").append(index).append("에 있다").toString();
    }
}