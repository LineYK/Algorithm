// 1409. Queries on a Permutation With Key

import java.util.LinkedList;

class Solution {
    public int[] processQueries(int[] queries, int m) {
        int[] res = new int[queries.length];
        LinkedList<Integer> link = new LinkedList<>();

        for (int i = 1; i <= m; i++) {
            link.add(i);
        }

        for(int i = 0; i < queries.length; i++) {
            res[i] = link.indexOf(queries[i]);
            int val = link.get(res[i]);
            link.remove(res[i]);
            link.addFirst(val);
        }

        return res;
    }
}