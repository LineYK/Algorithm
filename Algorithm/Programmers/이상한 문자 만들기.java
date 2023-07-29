// 이상한 문자 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12930)

class Solution {
    // 0.15 ~ 0.20 ms
    public String solution(String s) {
        String[] strArr = s.toLowerCase().split(" ", -1);

        StringBuilder sb = new StringBuilder();
        for (String str : strArr) {
            // 공백이면 추가
            if (str.equals(""))
                sb.append(" ");
            else {
                for (int i = 0; i < str.length(); i++) {
                    if (i % 2 == 0)
                        sb.append(Character.toUpperCase(str.charAt(i)));
                    else
                        sb.append(str.charAt(i));
                }
                sb.append(" ");
            }
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    // 0.15 ~ 1.0 ms
    public String solution2(String s) {

        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        String[] array = s.split("");

        for (String str : array) {
            cnt = str.contains(" ") ? 0 : cnt + 1;
            if (cnt % 2 == 0)
                sb.append(str.toLowerCase());
            else
                sb.append(str.toUpperCase());
        }
        return sb.toString();
    }
}