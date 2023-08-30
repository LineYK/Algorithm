// 1816. Truncate Sentence

class Solution {
    public String truncateSentence(String s, int k) {
        String[] ss = s.split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < k; i++)  {
            sb.append(ss[i]).append(" ");
        }

        return sb.toString().trim();
    }
}