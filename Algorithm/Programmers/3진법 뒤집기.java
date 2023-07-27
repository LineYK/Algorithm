// 3진법 뒤집기 (https://school.programmers.co.kr/learn/courses/30/lessons/68935)

class Solution {
    public int solution(int n) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        while(n != 0){
            sb.append(n%3);
            n = n/3;
        }
        int len = sb.length();
        
        for(int i = 0; i < len; i++) {
            answer += Math.pow(3, i) * (sb.charAt(len -1 - i) - '0');
        }
        return answer;
    }

    public int solution2(int n) {
        StringBuilder sb = new StringBuilder();
        while(n != 0){
            sb.append(n%3);
            n = n/3;
        }
        return Integer.parseInt(sb.toString(), 3);
    }
}

/** Integer.parseInt
 * 두번째 매개 변수 주면 그 변수로 진법으로 계산해서 int로 변환해준다.
 */