// 2828. Check if a String Is an Acronym of Words

import java.util.List;

class Solution {
    public boolean isAcronym(List<String> words, String s) {
        StringBuilder sb = new StringBuilder();

        for (String word : words) {
            sb.append(word.charAt(0));
        }

        return sb.toString().equals(s);
    }
}