// 1038. Binary Search Tree to Greater Sum Tree (https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree)

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
 * 
 * 아래 코드는 위 순서를 반대로 함
 */
class Solution {
    int pre = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root.right != null) bstToGst(root.right);
        pre = root.val = pre + root.val;
        if (root.left != null) bstToGst(root.left);
        return root;
    }
}