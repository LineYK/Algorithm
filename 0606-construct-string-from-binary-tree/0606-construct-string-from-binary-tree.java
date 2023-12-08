/**
606. 이진 트리에서 문자열 만들기

이진 트리의 루트가 주어졌을 때, 사전 순서 순회 방법을 사용하여 이진 트리에서 괄호와 정수로 구성된 문자열을 구축하여 반환합니다.

문자열과 원래 이진 트리 사이의 일대일 매핑 관계에 영향을 주지 않는 빈 괄호 쌍은 모두 생략합니다.

 
예제 1:
입력: root = [1,2,3,4]
Output: "1(2(4))(3)"
설명: 원래는 "1(2(4)())(3()())"여야 하지만 불필요한 빈 괄호 쌍을 모두 생략해야 합니다. "1(2(4))(3)"이 됩니다.

예제 2:
입력: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
설명: 첫 번째 예제와 거의 동일하지만, 입력과 출력 간의 일대일 매핑 관계를 끊기 위해 첫 번째 괄호 쌍을 생략할 수 없다는 점이 다릅니다.
 
제약 조건:

트리의 노드 수는 [1, 104] 범위에 있습니다.
-1000 <= Node.val <= 1000

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
    StringBuilder sb;

    public String tree2str(TreeNode root) {
        sb = new StringBuilder();
        
        dfs(root);
        return sb.toString();
    }

    void dfs(TreeNode node) {
        if (node == null) return;

        sb.append(node.val);
        
        if (node.left == null && node.right == null)
            return;
        
        sb.append("(");
        dfs(node.left);
        sb.append(")");
        
        if (node.right != null){
            sb.append("(");
            dfs(node.right);
            sb.append(")");
        }
    }
}