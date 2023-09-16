// 1584. Min Cost to Connect All Points (https://leetcode.com/problems/min-cost-to-connect-all-points)

import java.util.*;

// MST (Minimum Spanning Tree) 최소 신장 트리
/* 
    그래프에서 그래프의 모든 정점을 연결하되,
    사이클이 존재하지 않도록 모든 정점을 간선으로 연결하는 것을 의미한다. 
    이때, 간선의 가중치 합을 최소로 하며 연결하여야 한다.
    이때 생성되는 최소 스패닝 트리는 무조건 하나의 그래프에서 하나만 생성된다고는 보장하지 못한다.
 */

// 프림 알고리즘(Prim's Algorithm)
/*
    하나의 시작점을 잡고 시작점과 연결된 정점들에 대해 가장 가중치가 작은 간선부터 연결해주면서 
    최소 스패닝 트리를 만들어 나가는 알고리즘
 */
class Solution {
    public int findDist(int[][] points, int a, int b) {
        return Math.abs(points[a][0] - points[b][0]) + Math.abs(points[a][1] - points[b][1]);
    }

    public int minCostConnectPoints(int[][] points) {
        int res = 0, len = points.length;
        Set<Integer> mst = new HashSet<>();
        mst.add(0);
        int[] dist = new int[len];

        for (int i = 1; i < len; i++) 
            dist[i] = findDist(points, 0, i);

        while(mst.size() != len) {
            int next = -1;
            for (int i = 0; i < len; i++) {
                if (mst.contains(i)) continue;
                if (next == -1 || dist[next] > dist[i]) next = i;
            }
            mst.add(next);
            res += dist[next];

            for (int i = 0; i < len; i++ ) {
                if(!mst.contains(i))
                    dist[i] = Math.min(dist[i], findDist(points, i, next));
            }
        }
        return res;
    }
}