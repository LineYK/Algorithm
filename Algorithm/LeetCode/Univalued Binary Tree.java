// 965. Univalued Binary Tree (https://leetcode.com/problems/univalued-binary-tree)

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
    public boolean isUnivalTree(TreeNode root) {
        int val = root.val;

        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);

        while(!que.isEmpty()) {
            TreeNode node = que.poll();
            if (val != node.val) return false;
            if (node.left != null) que.offer(node.left);
            if (node.right != null) que.offer(node.right);
        }

        return true;
    }
}

// DFS
class Solution2 {
    int val;
    boolean flag = true;
    public boolean isUnivalTree(TreeNode root) {
        val = root.val;
        dfs(root);
        return flag;
    }

    private void dfs(TreeNode node) {
        if (node == null) return;
        if (val != node.val) flag = false;
        if (flag){
            dfs(node.left);
            dfs(node.right);
        }
    }
}

// DFS2
class Solution3 {
    int val = -1;
    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;
        if (val < 0) val = root.val;
        return root.val == val && isUnivalTree(root.left)  && isUnivalTree(root.right);
    }
}