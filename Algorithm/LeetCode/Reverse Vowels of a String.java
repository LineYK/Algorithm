// 345. Reverse Vowels of a String (https://leetcode.com/problems/reverse-vowels-of-a-string)

import java.util.*;

class Solution {
    public String reverseVowels(String s) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        char[] chars = s.toCharArray();

        int start = 0, end = s.length()-1;

        while (start < end) {
            while(start < end && !vowels.contains(chars[start])){
                start++;
            }

            while(start < end && !vowels.contains(chars[end])){
                end--;
            }
            char temp = chars[start];
            chars[start] = chars[end];
            chars[end] = temp;

            start++;
            end--;

        }

        return new String(chars);
    }
}