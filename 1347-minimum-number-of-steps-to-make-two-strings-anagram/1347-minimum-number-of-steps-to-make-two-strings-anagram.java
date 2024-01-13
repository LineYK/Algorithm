/*
1347. 두 문자열 애너그램을 만들기 위한 최소 단계 수

길이가 같은 s와 t의 두 문자열이 주어지며, 
한 단계에서 t의 문자를 선택하여 다른 문자로 바꿀 수 있습니다.

t를 s의 아나그램으로 만들기 위한 최소 단계 수를 반환합니다.

문자열의 아나그램은 동일한 문자를 다른(또는 동일한) 순서로 포함하는 문자열입니다.

예시 1:

입력: s = "bab", t = "aba"
출력: 1
설명: 설명: t의 첫 번째 'a'를 b로 바꾸면 t = "bba"가 되고, 이는 s의 아나그램이 됩니다.

예제 2:
입력: s = "leetcode", t = "practice"
출력 5
설명: t에서 'p', 'r', 'a', 'i', 'c'를 적절한 문자로 바꾸어 t의 아나그램을 s로 만듭니다.

예제 3:
입력: s = "anagram", t = "mangaar"
Output: 0
설명: "anagram"과 "mangaar"는 아나그램입니다.
 

제약 조건:
1 <= s.length <= 5 * 104
s.length == t.length
s와 t는 영문 소문자로만 구성됩니다.
*/

class Solution {
    public int minSteps(String s, String t) {
        int[] alpha = new int[26];

        for (char c : s.toCharArray()) {
            alpha[c - 'a'] += 1;
        }

        for (char c : t.toCharArray()) {
            if(alpha[c - 'a'] > 0) alpha[c - 'a'] -= 1;
        }

        return Arrays.stream(alpha).sum();
    }
}