// 226. Invert Binary Tree (https://leetcode.com/problems/invert-binary-tree)

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

// DFS
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return root;
        invertTree(root.left);
        invertTree(root.right);
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        return root;
    }
}

// BFS
class Solution2 {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return root;
       
       Queue<TreeNode> queue = new LinkedList<>();

       queue.offer(root);

       while (!queue.isEmpty()) {
           TreeNode curNode = queue.poll();

           TreeNode temp = curNode.left;
           curNode.left = curNode.right;
           curNode.right = temp;

           if (curNode.left != null) queue.offer(curNode.left);
           if (curNode.right != null) queue.offer(curNode.right);
       }

        return root;
    }
}