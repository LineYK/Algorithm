// 1720. Decode XORed Array (https://leetcode.com/problems/decode-xored-array)

class Solution {
    public int[] decode(int[] encoded, int first) {
        int[] ans = new int[encoded.length + 1];
        ans[0] = first;
        for (int i = 0; i < encoded.length; i++) {
            ans[i+1] = ans[i] ^ encoded[i];
        }
        return ans;
    }
}

/** ^ 연산자
 * XOR 비트 연산자
 * 0 0 일 때 0
 * 1 0 일 때 1
 * 0 1 일 때 1
 * 1 1 일 때 0
 */