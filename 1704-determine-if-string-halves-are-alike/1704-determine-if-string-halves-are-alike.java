/*
1704. 문자열 반쪽이 같은지 확인하기

길이가 짝수인 문자열 s가 주어집니다. 이 문자열을 길이가 같은 두 개의 반으로 나누고, a를 첫 번째 반, b를 두 번째 반으로 하세요.

두 문자열의 모음 개수가 같으면('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U') 두 문자열은 유사합니다. s는 대문자와 소문자를 포함한다는 점에 유의하세요.

a와 b가 같으면 참을 반환합니다. 그렇지 않으면 false를 반환합니다.

 

예제 1:
입력: s = "book"
출력: true
설명: a = "bo", b = "ok". a에는 모음이 1개, b에는 모음이 1개 있습니다. 따라서 이들은 유사합니다.

예제 2:
입력: s = "textbook"
출력: false
설명: a = "text", b = "book". a는 모음이 1개이고 b는 모음이 2개이므로 서로 같지 않습니다.
모음 o가 두 번 계산된다는 점에 유의하세요.
 

제약 조건입니다:

2 <= s.length <= 1000
s.length는 짝수입니다.
s는 대문자와 소문자로 구성됩니다.
*/

class Solution {
    public boolean halvesAreAlike(String s) {
        char[] chars = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        int len = s.length()/2;
        s = s.toLowerCase();

        char[] sArr = s.toCharArray();

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < chars.length; j++) 
                if (chars[j] == sArr[i]) {
                    cnt++;
                    break;
                }
        }

        for (int i = len; i < sArr.length; i++) {
            for (int j = 0; j < chars.length; j++) 
                if (chars[j] == sArr[i]) {
                    cnt--;
                    break;
                }
        }

        return cnt == 0;
    }
}