// 1448. Count Good Nodes in Binary Tree (https://leetcode.com/problems/count-good-nodes-in-binary-tree)

// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int cnt;

    public int goodNodes(TreeNode root) {
        int max = Integer.MIN_VALUE;
        cnt = 0;
        dfs(root, max);

        return cnt;
    }

    private void dfs(TreeNode node, int max) {
        if (node.val >= max) {
            cnt++;
            max = node.val;
        }

        if (node.left != null) {
            dfs(node.left, max);
        }

        if (node.right != null) {
            dfs(node.right, max);
        }

    }
}