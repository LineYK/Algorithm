// 1282. Group the People Given the Group Size They Belong To (https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

import java.util.*;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                map.put(groupSizes[i], new ArrayList<>());
            }

            List<Integer> group = map.get(groupSizes[i]);
            group.add(i);

            if (group.size() == groupSizes[i]) {
                res.add(group);
                map.put(groupSizes[i], new ArrayList<>());
            }
        }

        return res;
    }

    public List<List<Integer>> groupThePeople2(int[] groupSizes) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            List<Integer> group = map.computeIfAbsent(groupSizes[i], k -> new ArrayList<>());
            group.add(i);

            if (group.size() == groupSizes[i]) {
                res.add(group);
                map.put(groupSizes[i], new ArrayList<>());
            }
        }

        return res;
    }
}