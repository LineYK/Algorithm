// JadenCase 문자열 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12951#)

class Solution {
    public String solution(String s) {
        String[] strArr = s.toLowerCase().split(" ");
        // 마지막에 공백이 있으면 추가
        if(s.substring(s.length() - 1, s.length()).equals(" ")) {
            strArr[strArr.length-1] += " ";
        }
        StringBuilder sb = new StringBuilder();
        for(String str : strArr) {
            // 공백이면 추가
            if (str.equals("")) 
                sb.append(" ");
            else 
                sb.append(Character.toUpperCase(str.charAt(0))).append(str.substring(1, str.length())).append(" ");
        }
        sb.deleteCharAt(sb.length()-1);
        return sb.toString();
    }
}

/* 문자열 안에 단어 순서 뒤집기(Reverse Words in a String)와 비슷한 문제인줄 알았으나
 * 이 문제는 공백까지 신경써야 해서 오래걸림
 */