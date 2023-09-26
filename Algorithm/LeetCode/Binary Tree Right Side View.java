// 199. Binary Tree Right Side View (https://leetcode.com/problems/binary-tree-right-side-view)

import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// BFS
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        
        if (root == null) return res;

        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root);
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            TreeNode node = null;
            while(size > 0) {
                node = queue.poll();
                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
                size--;
            }
            res.add(node.val);
        }

        return res;
    }
}