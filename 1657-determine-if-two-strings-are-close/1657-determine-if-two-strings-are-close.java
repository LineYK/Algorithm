/*
1657. 두 문자열이 가까운지 확인하기

두 문자열은 다음 연산을 사용하여 다른 문자열에서 하나를 얻을 수 있는 경우 가까운 것으로 간주합니다:

연산 1: 두 개의 기존 문자를 바꿉니다.
예: abcde -> aecdb
연산 2: 한 기존 문자의 모든 항목을 다른 기존 문자로 변환하고 다른 문자에 대해서도 동일한 작업을 수행합니다.
예: aacabb -> bbcbaa(모든 a가 b로 바뀌고 모든 b가 a로 바뀜)
두 문자열에 대해 필요한 만큼 연산을 사용할 수 있습니다.

두 개의 문자열, 단어1과 단어2가 주어지면 단어1과 단어2가 가까우면 참을 반환하고 그렇지 않으면 거짓을 반환합니다.

 
예제 1:
입력: word1 = "abc", word2 = "bca"
출력: true
설명: 두 번의 연산을 통해 word1에서 word2를 얻을 수 있습니다.
연산 1 적용: "abc" -> "acb"
연산 1 적용: "acb" -> "bca"

예제 2:
입력: word1 = "a", word2 = "aa"
출력: false
설명: 어떤 연산으로도 word1에서 word2를 얻거나 그 반대로 얻을 수 없습니다.

예제 3:
입력: word1 = "cabbba", word2 = "abbccc"
출력: true
설명: 3번의 연산을 통해 word1에서 word2를 얻을 수 있습니다.
연산 1 적용: "cabbba" -> "caabbb"
연산 2 적용: "caabbb" -> "baaccc"
연산 2 적용: "baaccc" -> "abbccc"
 

제약 조건:

1 <= word1.length, word2.length <= 105
단어1과 단어2는 영어 소문자만 포함합니다.
*/

class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] w1 = new int[26];
        int[] w2 = new int[26];

        for (char c : word1.toCharArray())
            w1[c - 'a']++;

        for (char c : word2.toCharArray())
            w2[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((w1[i] == 0 && w2[i] != 0) || (w1[i] != 0 && w2[i] == 0)) {
                return false;
            }
        }

        Arrays.sort(w1);
        Arrays.sort(w2);

        for(int i = 0; i < 26; i++) {
            if(w1[i] != w2[i]) return false;
        }

        return true;
    }
}