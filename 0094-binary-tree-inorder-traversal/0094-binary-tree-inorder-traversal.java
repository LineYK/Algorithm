/**
94. 이진 트리 순서 탐색

이진 트리의 루트가 주어졌을 때, 그 노드 값의 순서대로 순회하는 것을 반환합니다.

예제 1:
입력: root = [1,null,2,3]
Output: [1,3,2]

예제 2:
입력: root = []
Output: []

예 3: 예제 3:
입력: root = [1]
Output: [1]
 

제약 조건:

트리의 노드 수는 [0, 100] 범위에 있습니다.
-100 <= Node.val <= 100
 

후속 조치: 재귀적 솔루션은 사소한데, 반복적으로 할 수 있을까요?

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
    List<Integer> res;

    public List<Integer> inorderTraversal(TreeNode root) {
        res = new ArrayList<>();
        dfs(root);
        return res;
    }

    void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        res.add(node.val);
        dfs(node.right);
    }
}