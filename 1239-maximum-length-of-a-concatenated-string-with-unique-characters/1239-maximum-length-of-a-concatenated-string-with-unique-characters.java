/*
1239. 고유 문자가 포함된 연결된 문자열의 최대 길이

문자열 배열 배열이 주어집니다. 
문자열 s는 고유 문자를 가진 배열의 연속을 연결하여 형성됩니다.

s의 가능한 최대 길이를 반환합니다.
시퀀스는 나머지 요소의 순서를 변경하지 않고 
일부 또는 전혀 요소를 삭제하여 다른 배열에서 파생할 수 있는 배열입니다.


예제 1:
입력: arr = ["un","iq","ue"]
출력: 4
설명: 모든 유효한 연결이 있습니다:
- ""
- "un"
- "iq"
- "ue"
- "uniq"("un" + "iq")
- "ique"("iq" + "UE")
최대 길이는 4입니다.

예제 2:
입력: arr = ["cha","r","act","ers"]
Output: 6
설명: 가능한 가장 긴 유효한 연결은 "chaers"("cha" + "ers")와 "acters"("act" + "ers")입니다.

예제 3:
입력: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
설명: 배열에 26개의 문자가 모두 포함된 유일한 문자열입니다.
 

제약 조건:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
배열[i]에는 영문 소문자만 포함됩니다.
*/

class Solution {
    private int res = 0;

    public int maxLength(List<String> arr) {
        dfs(arr, "", 0);
        return res;
    }

    void dfs(List<String> arr, String cur, int start) {
        if (res < cur.length()) res = cur.length();

        for (int i = start; i < arr.size(); i++) {
            if (!isVaild(cur, arr.get(i))) continue;
            dfs(arr, cur + arr.get(i), i+1);
        }
    }

    boolean isVaild(String curStr, String newStr) {
        int[] arr = new int[26];
        for(char c : newStr.toCharArray()) {
            if(++arr[c - 'a'] == 2) return false;
            if(curStr.contains(c+"")) return false;
        }
        return true;
    }
} 