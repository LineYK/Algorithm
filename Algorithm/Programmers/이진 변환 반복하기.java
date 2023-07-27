// 이진 변환 반복하기 (https://school.programmers.co.kr/learn/courses/30/lessons/70129)

class Solution {
    public int[] solution(String s) {
        int cnt = 0, zero = 0;
    
        while(!s.equals("1")){
            cnt += 1;
            String removed = String.join("", s.split("0"));
            zero += s.length() - removed.length();
            s = Integer.toBinaryString(removed.length());      
        }
        int[] answer = new int[]{cnt, zero};
        return answer;
    }

        public int[] solution2(String s) {
        int cnt = 0, zero = 0;
    
        while(!s.equals("1")){
            cnt += 1;
            String removed = s.replaceAll("0", "");
            zero += s.length() - removed.length();
            s = Integer.toBinaryString(removed.length());      
        }
        int[] answer = new int[]{cnt, zero};
        return answer;
    }
}