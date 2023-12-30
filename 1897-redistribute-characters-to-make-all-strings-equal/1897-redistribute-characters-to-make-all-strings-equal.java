/*
1897. 모든 문자열을 동일하게 만들기 위해 문자 재분배하기

0 인덱스의 문자열 단어 배열이 주어집니다.

한 번의 연산에서, 단어[i]가 비어 있지 않은 문자열인 두 개의 서로 다른 인덱스 i와 j를 선택하고, 단어[i]에서 단어[j]의 임의의 위치로 문자를 이동합니다.

원하는 수의 연산을 사용하여 단어의 모든 문자열을 동일하게 만들 수 있으면 참을 반환하고, 그렇지 않으면 거짓을 반환합니다.

 

예제 1:
입력: words = ["abc","aabc","bc"]
출력: true
설명: words[1]의 첫 번째 'a'를 words[2]의 앞쪽으로 이동합니다,
하여 words[1] = "abc", words[2] = "abc"를 만듭니다.
이제 모든 문자열이 "abc"와 같으므로 참을 반환합니다.

예 2:
입력: words = ["ab","a"]
출력: false
설명: 이 연산을 사용하여 모든 문자열을 동일하게 만드는 것은 불가능합니다.

 

제약 조건이 있습니다:
    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i]는 소문자 영어 문자로 구성됩니다.
*/

class Solution {
    public boolean makeEqual(String[] words) {
        int len = words.length;

        Map<Character, Integer> map = new HashMap<>();

        for (String word : words) {
            for (char c : word.toCharArray()){
                map.put(c, map.getOrDefault(c, 0) + 1);
            }
        }

        for (Character c : map.keySet()) {
            if (map.get(c) % len != 0) return false;
        }

        return true;
    }
}