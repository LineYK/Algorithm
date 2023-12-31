/*
1624. 두 개의 동일한 문자 사이의 가장 큰 하위 문자열

문자열 s가 주어졌을 때, 두 개의 동일한 문자 사이에서 두 문자를 제외한 가장 긴 부분 문자열의 길이를 반환합니다. 그러한 부분 문자열이 없으면 -1을 반환합니다.

부분 문자열은 문자열 내의 연속된 문자 시퀀스입니다.

 

예제 1:
입력: s = "aa"
Output: 0
설명: 여기서 최적의 부분 문자열은 두 'a' 사이에 빈 부분 문자열입니다.

예제 2:
입력: s = "abca"
Output: 2
설명: 여기서 최적의 부분 문자열은 "bc"입니다.

예제 3:
입력: s = "cbzxy"
Output: -1
설명: s에 두 번 나타나는 문자가 없습니다.
 

제약 조건:
1 <= s.length <= 300
s에는 영문 소문자만 포함됩니다.
*/

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] alphabet = new int[26];
        int max = -1;

        char[] chars = s.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            int idx = chars[i] - 'a';
            if (alphabet[idx] > 0) max = Math.max(max, i - alphabet[idx]);
            else alphabet[idx] = i + 1;
        }

        return max;
    }
}