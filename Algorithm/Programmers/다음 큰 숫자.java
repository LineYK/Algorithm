// 다음 큰 숫자 (https://school.programmers.co.kr/learn/courses/30/lessons/12911)

class Solution {
    // 효율성 X
    public int solution(int n) {
        int ans = 0;
        String binaryN = Integer.toBinaryString(n);
        int len = String.join("", binaryN.split("0")).length();
        for (int i = 1; n + i <= n << 1; i++) {
            ans = n + i;
            String binAns = Integer.toBinaryString(ans);
            int ansLen = String.join("", binAns.split("0")).length();
            if (len == ansLen)
                break;
        }
        return ans;
    }

    // bitCount 사용으로 통과
    public int solution2(int n) {
        int ans = 0;
        int len = Integer.bitCount(n);
        for (int i = 1; n + i <= n << 1; i++) {
            ans = n + i;
            int ansLen = Integer.bitCount(ans);
            if (len == ansLen)
                break;
        }
        return ans;
    }
}