// 1647. Minimum Deletions to Make Character Frequencies Unique (https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique)

import java.util.*;

class Solution {
    public int minDeletions(String s) {
        int res = 0;

        char[] chars = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();

        for (char c : chars) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        Set<Integer> set = new HashSet<>();

        for (Character c : map.keySet()) {
            int count = map.get(c);
            while(count > 0 && !set.add(count)){
                count--;
                res++;
            }
        }

        return res;
    }
}

class Solution2 {
    public int minDeletions(String s) {
        int res = 0;
        Set<Integer> set = new HashSet<>();
        int[] cnt = new int[26];

        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            while(cnt[i] > 0 && !set.add(cnt[i])){
                cnt[i]--;
                res++;
            }
        }

        return res;
    }
}