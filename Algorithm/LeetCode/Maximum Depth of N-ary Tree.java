// 559. Maximum Depth of N-ary Tree (https://leetcode.com/problems/maximum-depth-of-n-ary-tree)

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

import java.util.*;

// BFS
class Solution {
    public int maxDepth(Node root) {
        int res = 0;
        if (root == null) return res;

        Queue<Node> que = new LinkedList<>();
        que.offer(root);

        while (!que.isEmpty()) {
            int size = que.size();
            res++;
            while (size-- > 0) {
                Node node = que.poll();
                for (Node n : node.children) que.offer(n);
            }
        }

        return res;
    }
}

// DFS
class Solution2 {
    public int maxDepth(Node root) {
        int res = 0;
        if (root == null) return res;

        for (Node node : root.children) {
            res = Math.max(res, maxDepth(node));
        }

        return res+1;
    }
}