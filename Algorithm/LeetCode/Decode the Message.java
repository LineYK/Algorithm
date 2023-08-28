// 2325. Decode the Message (https://leetcode.com/problems/decode-the-message)

import java.util.*;

class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character, Character> map = new HashMap<>();
        char alphabet = 'a';

        char[] keys = key.replaceAll(" ", "").toCharArray();

        for (char k : keys) {
            if(!map.containsKey(k)) map.put(k, alphabet++);
        }
        char[] messaChar = message.toCharArray();
        StringBuilder sb = new StringBuilder();

        for (char m : messaChar) {
            if(m == ' ') sb.append(' ');
            else sb.append(map.get(m));
        }

        return sb.toString();
    }
}