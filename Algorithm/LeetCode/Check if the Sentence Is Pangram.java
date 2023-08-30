// 1832. Check if the Sentence Is Pangram (https://leetcode.com/problems/check-if-the-sentence-is-pangram)
/*
    팡그램(pangram)은 모든 알파벳 문자가 최소한 한 번씩 등장하는 문장
 */
import java.util.*;

class Solution {
    public boolean checkIfPangram(String sentence) {
        Set<Character> set = new HashSet<>();
        char[] chars = sentence.toCharArray();

        for (char c : chars)
            set.add(c);

        return set.size() == 26;
    }

    public boolean checkIfPangram2(String sentence) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (sentence.indexOf(c) < 0) {
                return false;
            }
        }
        return true;
    }
}