// 700. Search in a Binary Search Tree (https://leetcode.com/problems/search-in-a-binary-search-tree)

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

/* Binary Search Tree, BST는 빠른 탐색, 삽입, 삭제가 가능한 자료 구조
 * 왼쪽 노드는 부모 노드보다 값이 작고 오른쪽 노드는 값이 크다.
 * 위와 같은 특징을 사용하여 불필요한 탐색이 필요없어지고 
 * 그 결과 평균 탐색 시간이 O(logn)으로 배열이나, 링크드 리스트에 비해 굉장히 빠른 속도로 탐색하는 것이 가능하다
 */

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) return null;
        if (root.val == val) return root;
        
        return root.val > val ? searchBST(root.left, val) : searchBST(root.right, val);
    }
}