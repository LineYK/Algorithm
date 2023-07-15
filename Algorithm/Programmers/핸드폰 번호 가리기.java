// 핸드폰 번호 가리기 (https://school.programmers.co.kr/learn/courses/30/lessons/12948)

class Solution {
    public String solution(String phone_number) {
        StringBuilder sb = new StringBuilder(phone_number);
        String lastNum = sb.substring(phone_number.length()-4, phone_number.length());
        String starNum = sb.substring(0, phone_number.length()-4).replaceAll("[0-9]", "*");
        
        return new StringBuilder().append(starNum).append(lastNum).toString();
    }
}