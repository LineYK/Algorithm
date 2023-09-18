// 1337. The K Weakest Rows in a Matrix (https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix)

import java.util.*;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] res = new int[k];
        int[] cntKeys = new int[mat.length];
        Map<Integer, PriorityQueue<Integer>> map = new HashMap<>();

        for (int i = 0; i < mat.length; i++) {
            int cnt = 0;
            for (int p : mat[i]) {
                if (p == 1)
                    cnt++;
                else
                    break;
            }
            if (!map.containsKey(cnt))
                map.put(cnt, new PriorityQueue<>());
            map.get(cnt).add(i);
            cntKeys[i] = cnt;
        }
        Arrays.sort(cntKeys);

        for (int i = 0; i < res.length; i++) {
            res[i] = map.get(cntKeys[i]).poll();
        }

        return res;
    }
}

class Solution2 {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] != b[0] ? b[0] - a[0] : b[1] - a[1]);
        int[] ans = new int[k];

        for (int i = 0; i < mat.length; i++) {
            pq.offer(new int[] { numOnes(mat[i]), i });
            if (pq.size() > k)
                pq.poll();
        }

        while (k > 0)
            ans[--k] = pq.poll()[1];

        return ans;
    }

    private int numOnes(int[] row) {
        int lo = 0;
        int hi = row.length;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (row[mid] == 1)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
}