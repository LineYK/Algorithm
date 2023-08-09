// 숫자 문자열과 영단어 (https://school.programmers.co.kr/learn/courses/30/lessons/81301)

class Solution {
    public int solution(String s) {
        String[] nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for(int i = 0; i < nums.length; i++) {
            s = s.replaceAll(nums[i], Integer.toString(i));
        }
        
        return Integer.parseInt(s);
    }
}