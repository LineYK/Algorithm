/*
242. 유효한 아나그램

두 문자열 s와 t가 주어졌을 때, t가 s의 아나그램이면 참을 반환하고 그렇지 않으면 거짓을 반환합니다.

아나그램은 다른 단어나 구의 글자를 재배열하여 형성된 단어 또는 구문으로, 일반적으로 원래의 모든 글자를 정확히 한 번씩 사용합니다.

 

예제 1:
입력: s = " anagram", t = " nagaram"
출력: true

예제 2:
입력: s = ""rat"", t = ""car""
출력: false
 

제약 조건:
1 <= s.length, t.length <= 5 * 104
s와 t는 영문 소문자로 구성됩니다.
*/

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();

        Arrays.sort(sChars);
        Arrays.sort(tChars);

        for (int i = 0; i < Math.max(sChars.length, tChars.length); i++) {
            if (sChars[i] != tChars[i]) return false;
        }

        return true;
    }
}