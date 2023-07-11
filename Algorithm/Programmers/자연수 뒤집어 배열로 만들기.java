// 자연수 뒤집어 배열로 만들기 (https://school.programmers.co.kr/learn/courses/30/lessons/12932)

class Solution {

    // O(n)
    public int[] solution(long n) {
        String num = Long.toString(n);
        int[] ans = new int[num.length()];
        for (int i = 0; i < ans.length; i ++) {
            ans[i] = num.charAt(ans.length - 1 - i) - '0';
        }
        return ans;
    }

    public int[] solution2(long n) {
        return new StringBuilder().append(n).reverse().chars().map(e -> e - '0').toArray();
    }

    public int[] solution3(long n) {
        return new StringBuilder().append(n).reverse().chars().map(Character::getNumericValue).toArray();
    }
}