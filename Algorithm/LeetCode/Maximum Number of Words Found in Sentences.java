// 2114. Maximum Number of Words Found in Sentences (https://leetcode.com/problems/maximum-number-of-words-found-in-sentences)

import java.util.stream.Stream;

class Solution {
    public int mostWordsFound(String[] sentences) {
        int ans = 0;
        for (String s : sentences) {
            ans = Math.max(ans, s.split(" ").length);
        }
        return ans;
    }

    public int mostWordsFound2(String[] sentences) {
        return 1 + Stream.of(sentences).mapToInt(s -> (int)s.chars().filter(ch -> ch == ' ').count()).max().getAsInt();
    }
}