// 1859. Sorting the Sentence (https://leetcode.com/problems/sorting-the-sentence)

class Solution {
    public String sortSentence(String s) {
        String[] split = s.split(" ");

        String[] res = new String[split.length];

        for (String str : split) {
            int index = str.charAt(str.length()-1) - '0' -1;
            res[index] = str.substring(0, str.length() -1);
        }

        return String.join(" ", res);
    }
}