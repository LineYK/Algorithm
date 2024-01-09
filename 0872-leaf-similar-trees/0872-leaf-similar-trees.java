/*
872. 잎이 비슷한 나무

이진 트리의 모든 나뭇잎을 왼쪽에서 오른쪽 순서로 고려하면, 그 나뭇잎의 값은 나뭇잎 값 수열을 형성합니다.



예를 들어, 위의 주어진 트리에서 잎 값 수열은 (6, 7, 4, 9, 8)입니다.

두 이진 트리의 잎 값 수열이 같으면 잎이 비슷한 것으로 간주합니다.

주어진 두 트리의 헤드 노드가 root1과 root2인 경우, 두 트리가 잎이 유사할 때만 참을 반환합니다.

 

예제 1:
입력: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
출력: true

예제 2:
입력: root1 = [1,2,3], root2 = [1,3,2]
출력: false
 

제약 조건:

각 트리의 노드 수는 [1, 200] 범위에 있습니다.
주어진 두 트리 모두 [0, 200] 범위의 값을 갖습니다.

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