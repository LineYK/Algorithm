// 최댓값과 최솟값 (https://school.programmers.co.kr/learn/courses/30/lessons/12939)

class Solution {
    public String solution(String s) {
        String[] ss = s.split(" ");
        int max = Integer.parseInt(ss[0]), min = Integer.parseInt(ss[0]);
        for (int i = 1; i < ss.length; i++) {
            max = Math.max(max, Integer.parseInt(ss[i]));
            min = Math.min(min, Integer.parseInt(ss[i]));
        }
        return new StringBuilder().append(min).append(" ").append(max).toString();
    }
}