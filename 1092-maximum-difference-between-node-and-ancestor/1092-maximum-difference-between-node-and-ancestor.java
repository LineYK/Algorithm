/**
1026. 노드와 어카운트 간의 최대 차이점


이진 트리의 루트가 주어졌을 때, 서로 다른 노드 a와 b가 존재하고 v = |a.val - b.val|이고 a가 b의 조상인 경우의 최대값 v를 구합니다.
노드 a는 a의 모든 자식이 b와 같거나 a의 모든 자식이 b의 조상인 경우 b의 조상입니다.

 
예제 1:
입력: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
설명: 다양한 조상 노드 차이점이 있으며, 그 중 일부는 다음과 같습니다:
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
가능한 모든 차이 중에서 최대값인 7은 |8 - 1| = 7로 구할 수 있습니다.

예 2:
입력: root = [1,null,2,null,0,3]
Output: 3

 

제약 조건:
    트리의 노드 수는 [2, 5000] 범위에 있습니다.
    0 <= Node.val <= 10^5

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

    int res = 0;
    public int maxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return res;
    }

    void dfs(TreeNode node, int min, int max) {
        if (node != null) {
            res = Math.max(res, Math.abs(min - node.val));
            res = Math.max(res, Math.abs(max - node.val));

            if (node.left != null) 
                dfs(node.left, Math.min(min, node.left.val), Math.max(max, node.left.val));
            if (node.right != null) 
                dfs(node.right, Math.min(min, node.right.val), Math.max(max, node.right.val));
        }
    }
}