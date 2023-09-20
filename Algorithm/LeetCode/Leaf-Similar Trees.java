// 872. Leaf-Similar Trees (https://leetcode.com/problems/leaf-similar-trees)

import java.util.*;

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        String rOne = dfs(root1);
        String rTwo = dfs(root2);

        return rOne.equals(rTwo);
    }

    private String dfs(TreeNode node) {
        StringBuilder sb = new StringBuilder();

        if (node.left != null)
            sb.append(dfs(node.left));
        if (node.right != null)
            sb.append(dfs(node.right));
        if (node.left == null && node.right == null)
            sb.append(node.val).append("/");

        return sb.toString();
    }
}

// Stack + DFS
class Solution2 {
       public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> s1 = new Stack<>(), s2 = new Stack<>();
        s1.push(root1); s2.push(root2);
        while (!s1.empty() && !s2.empty())
            if (dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }

    public int dfs(Stack<TreeNode> s) {
        while (true) {
            TreeNode node = s.pop();
            if (node.right != null) s.push(node.right);
            if (node.left != null) s.push(node.left);
            if (node.left == null && node.right == null) return node.val;
        }
    }
}