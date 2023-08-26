// 1773. Count Items Matching a Rule (https://leetcode.com/problems/count-items-matching-a-rule/)

import java.util.List;

class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int cnt = 0;
        int target = ruleKey.equals("type") ? 0 : ruleKey.equals("color") ? 1 : 2;

        for (List<String> item : items) {
            if (item.get(target).equals(ruleValue)) cnt++;
        }

        return cnt;
    }
}