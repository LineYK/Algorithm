// 푸드 파이트 대회 (https://school.programmers.co.kr/learn/courses/30/lessons/134240)

class Solution {

    // 이쪽이 더 빠름
    public String solution(int[] food) {
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < food.length; i++) {
            for (int j = 1; j <= food[i] / 2; j++) {
                sb.append(i);
            }
        }
        String str = sb.toString();
        sb.append('0');
        sb.append(new StringBuilder(str).reverse());

        return sb.toString();
    }

    public String solution2(int[] food) {
        StringBuilder sb = new StringBuilder("0");

        for (int i = food.length - 1; i > 0; i--) {
            for (int j = 0; j < food[i] / 2; j++) {
                sb.append(i).insert(0, i);
            }
        }

        return sb.toString();
    }
}