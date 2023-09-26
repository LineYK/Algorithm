// 2415. Reverse Odd Levels of Binary Tree (https://leetcode.com/problems/reverse-odd-levels-of-binary-tree)

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
    public TreeNode reverseOddLevels(TreeNode root) {
        if(root == null) return root;

        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root);

        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while(size-- > 0) {
                TreeNode node = queue.poll();
                if(node.left != null) queue.offer(node.left);
                if(node.right != null) queue.offer(node.right);
            }

            level++;
            if (level % 2 == 1 && !queue.isEmpty()) {
                int[] nums = new int[queue.size()];
                int i = 0;
                for (TreeNode node : queue) {
                    nums[i++] = node.val;
                }

                int j = queue.size() - 1;
                for (TreeNode node : queue) {
                    node.val = nums[j--];
                }

            }
        }
        return root;
    }
}