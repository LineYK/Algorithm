/*
1143. 최장 공통 부분수열

두 문자열 text1과 text2가 주어졌을 때, 
두 문자열의 최장 공통 부분수열의 길이를 반환합니다. 
공통 수열이 없으면 0을 반환합니다.

문자열의 하위 문자열은 원래 문자열에서 일부 문자를 추가하여 
원래 문자열에서 일부 문자(없음일 수도 있음)를 삭제하고 
나머지 문자의 상대적 순서를 변경하지 않고 생성된 새로운 문자열입니다.

예를 들어, "ace"는 "abcde"의 시퀀스입니다.

두 문자열의 공통 시퀀스는 두 문자열에 공통되는 시퀀스입니다.

 
예제 1:

입력: text1 = "abcde", text2 = "ace" 
출력 3  
설명: 최장 공통 부분수열은 "에이스"이며 그 길이는 3입니다.

예제 2:

입력: text1 = "abc", text2 = "abc"
출력: 3 3
설명: 최장 공통 부분수열은 "abc"이며 그 길이는 3입니다.

예제 3:

입력: text1 = "abc", text2 = "def"
출력: 0
설명: 이러한 공통 수열이 없으므로 결과는 0입니다.

 
제약 조건:
1 <= text1.length, text2.length <= 1000
text1과 text2는 소문자 영어 문자로만 구성됩니다.
*/

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length() + 1][text2.length() + 1];

        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1.charAt(i-1) == text2.charAt(j-1)) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[text1.length()][text2.length()];
    }
}