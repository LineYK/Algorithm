// 938. Range Sum of BST (https://leetcode.com/problems/range-sum-of-bst)

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    int res;

    public int rangeSumBST(TreeNode root, int low, int high) {
        res = 0;
        dfs(root, low, high);
        return res;
    }

    public void dfs(TreeNode node, int low, int high) {
        if (node != null) {
            if (node.val >= low && node.val <= high)
                res += node.val;

            if (node.val > low)
                dfs(node.left, low, high);

            if (node.val < high)
                dfs(node.right, low, high);
        }
    }

    public int rangeSumBST2(TreeNode root, int low, int high) {
        if (root == null)
            return 0;
        if (root.val > high)
            return rangeSumBST2(root.left, low, high);
        if (root.val < low)
            return rangeSumBST2(root.right, low, high);

        return root.val + rangeSumBST2(root.left, low, high) + rangeSumBST2(root.right, low, high);
    }
}