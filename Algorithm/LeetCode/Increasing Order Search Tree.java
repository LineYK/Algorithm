// 897. Increasing Order Search Tree (https://leetcode.com/problems/increasing-order-search-tree)

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
class Solution {
    List<Integer> list = new ArrayList<>();

    public TreeNode increasingBST(TreeNode root) {
        TreeNode res = new TreeNode();
        inorder(root);

        TreeNode node = res;
        for (Integer val : list) {
            node.right = new TreeNode(val);
            node = node.right;
        }

        return res.right;
    }

    private void inorder(TreeNode node) {
        if (node == null) return;

        inorder(node.left);
        list.add(node.val);
        inorder(node.right);
    }
}