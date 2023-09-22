// 94. Binary Tree Inorder Traversal (https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

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

// Inorder traversal (중위순회)
/* 왼쪽 서브트리를 중위순회한다.
 * 노드를 방문한다.
 * 오른쪽 서브트리를 중위순회한다.
 */
class Solution {
    List<Integer> res;

    public List<Integer> inorderTraversal(TreeNode root) {
        res = new ArrayList<>();
        dfs(root);
        return res;
    }

    private void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        res.add(node.val);
        dfs(node.right);
    }
}