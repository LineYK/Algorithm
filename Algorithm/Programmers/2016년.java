// 2016년 (https://school.programmers.co.kr/learn/courses/30/lessons/12901)

import java.time.LocalDate;

class Solution {
    public String solution(int month, int day) {
        String[] week = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
        LocalDate date = LocalDate.of(2016, month, day);
        int dayOfWeek = date.getDayOfWeek().ordinal();
        return week[dayOfWeek];
    }
}