/*
1531. 문자열 압축 II

실행 길이 인코딩은 연속된 동일한 문자(2회 이상 반복)를 문자의 연결과 문자의 개수(실행 길이)를 나타내는 숫자로 대체하는 방식으로 작동하는 문자열 압축 방법입니다. 예를 들어, 문자열 "aabccc"를 압축하려면 "aa"를 "a2"로 바꾸고 "ccc"를 "c3"로 바꿉니다. 따라서 압축된 문자열은 "a2bc3"이 됩니다.

이 문제에서는 단일 문자 뒤에 '1'을 추가하지 않는다는 점에 유의하세요.

문자열 s와 정수 k가 주어졌을 때, s의 실행 길이 인코딩 버전이 최소 길이를 갖도록 s에서 최대 k개의 문자를 삭제해야 합니다.

최대 k개의 문자를 삭제한 후 s의 실행 길이로 인코딩된 버전의 최소 길이를 구합니다.

 
예제 1:
입력: s = "aaabcccd", k = 2
Output: 4
설명: 아무것도 삭제하지 않고 s를 압축하면 길이 6의 "a3bc3d"가 됩니다. 'a' 또는 'c' 문자를 삭제하면 압축 문자열의 길이가 최대 5로 줄어드는데, 예를 들어 'a' 2개를 삭제하면 압축된 문자열의 길이는 abc3d가 되는 s = "abcccd"가 됩니다. 따라서 최적의 방법은 'b'와 'd'를 삭제하면 압축된 버전의 s는 길이가 4인 "a3c3"가 
예제 2:
입력: s = "aabbaa", k = 2
Output: 2
설명: 'b' 문자를 모두 삭제하면 결과 압축 문자열은 길이 2의 "a4"가 됩니다.

예제 3:
입력: s = "aaaaaaaaaaa", k = 0
Output: 3
설명: k는 0이므로 아무것도 삭제할 수 없습니다. 압축된 문자열은 길이 3의 "a11"입니다.
 

제약 조건:

1 <= s.length <= 100
0 <= k <= s.length
s에는 영문 소문자만 포함됩니다.
*/

class Solution {
    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        int[][] dp = new int[101][101];

        for(int i = 0; i <= n; i++)
            Arrays.fill(dp[i], 9999);

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {                
                int cnt = 0, del = 0;
                for(int l = i; l >= 1; l--) { 
                    if(s.charAt(l - 1) == s.charAt(i - 1)) cnt++;
                    else del++;
                    if(j - del >= 0) 
                        dp[i][j] = Math.min(dp[i][j], dp[l-1][j-del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1: 0));
                }
                if (j > 0)
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][k];
        
    }
}