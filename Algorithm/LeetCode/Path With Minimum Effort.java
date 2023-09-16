// 1631. Path With Minimum Effort (https://leetcode.com/problems/path-with-minimum-effort)

import java.util.*;

// Dijikstra
/*
 * 다이나믹 프로그래밍을 활용한 대표적인 최단 경로(Shortest Path) 탐색 알고리즘
 * 특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려줍니다. 
 * 다만 이 때 음의 간선을 포함할 수 없습니다. 
 * 물론 현실 세계에서는 음의 간선이 존재하지 않기 때문에 
 * 다익스트라는 현실 세계에 사용하기 매우 적합한 알고리즘 중 하나라고 할 수 있습니다.
 */
class Solution {
    int[] DIR = new int[] { 0, 1, 0, -1, 0 };

    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; i++)
            Arrays.fill(dist[i], Integer.MAX_VALUE);

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        minHeap.offer(new int[] { 0, 0, 0 }); // 거리, 행, 열

        while (!minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            int d = top[0], r = top[1], c = top[2];
            if (d > dist[r][c])
                continue;
            if (r == m - 1 && c == n - 1)
                return d;

            for (int i = 0; i < 4; i++) {
                int nr = r + DIR[i], nc = c + DIR[i + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newDist = Math.max(d, Math.abs(heights[nr][nc] - heights[r][c]));
                    if (dist[nr][nc] > newDist) {
                        dist[nr][nc] = newDist;
                        minHeap.offer(new int[] { dist[nr][nc], nr, nc });
                    }
                }
            }
        }
        return 0;
    }
}