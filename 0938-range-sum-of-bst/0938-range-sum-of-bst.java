/*
938. BST의 범위 합계

이진 검색 트리의 루트 노드와 낮은 값과 높은 값의 두 정수가 주어졌을 때, 포함 범위[낮음, 높음]의 값을 가진 모든 노드의 값의 합을 반환합니다.

예제 1:
입력: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
설명: 노드 7, 10, 15는 [7, 15] 범위에 있습니다. 7 + 10 + 15 = 32.

예제 2:
입력: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
설명: 노드 6, 7, 10은 [6, 10] 범위에 있습니다. 6 + 7 + 10 = 23.
 

제약 조건:

트리의 노드 수는 [1, 2 * 104] 범위에 있습니다.
1 <= Node.val <= 105
1 <= 낮음 <= 높음 <= 105
모든 Node.val은 고유합니다.
*/

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
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        if (root.val > high) return rangeSumBST(root.left, low, high);
        if (root.val < low) return rangeSumBST(root.right, low, high);

        return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
    }
}