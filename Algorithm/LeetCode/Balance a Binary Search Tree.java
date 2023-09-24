// 1382. Balance a Binary Search Tree (https://leetcode.com/problems/balance-a-binary-search-tree/)

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
    List<TreeNode> list = new ArrayList<>();

    public TreeNode balanceBST(TreeNode root) {
        inorderTraverse(root);
        return sort(0, list.size()-1);
    }

    private void inorderTraverse(TreeNode node) {
        if (node == null) return;

        inorderTraverse(node.left);
        list.add(node);
        inorderTraverse(node.right);
    }

    private TreeNode sort(int start, int end) {
        if (start > end) return null;
        int mid = (start + end) / 2;
        TreeNode node = list.get(mid);
        node.left = sort(start, mid -1);
        node.right = sort(mid + 1, end);
        return node;
    }
}