/**
1457. 이진 트리의 의사 팔린드로믹 경로

노드 값이 1에서 9까지의 숫자인 이진 트리가 주어집니다. 
이진 트리의 경로에 있는 노드 값 중 하나 이상의 순열이 팔린드롬인 경우 해당 경로를 유사 팔린드롬이라고 합니다.

루트 노드에서 리프 노드로 이어지는 유사 팔린드롬 경로의 수를 반환합니다.
 

예제 1:
입력: root = [2,3,1,3,1,null,1]
Output: 2
설명: 위 그림은 주어진 이진 트리를 나타냅니다. 
루트 노드에서 리프 노드로 가는 경로는 빨간색 경로 [2,3,3], 녹색 경로 [2,1,1], 경로 [2,3,1]의 세 가지가 있습니다. 
이 경로 중 빨간색 경로와 녹색 경로만 유사 팔린드롬 경로인데, 
빨간색 경로 [2,3,3]은 [3,2,3](팔린드롬)으로 재배열할 수 있고 
녹색 경로 [2,1,1]은 [1,2,1](팔린드롬)로 재배열할 수 있기 때문입니다.

예제 2:
입력: root = [2,1,1,1,1,3,널,널,널,널,널,널,널,1]
Output: 1
설명: 위 그림은 주어진 바이너리 트리를 나타냅니다. 
루트 노드에서 리프 노드로 가는 세 가지 경로가 있습니다: 녹색 경로 [2,1,1], 경로 [2,1,3,1], 경로 [2,1]. 
이 경로 중 [2,1,1]은 [1,2,1](팔린드롬)로 재배열될 수 있으므로 녹색 경로만 유사 팔린드롬입니다.

예 3:
입력: root = [9]
Output: 1
 

제약 조건입니다:
트리의 노드 수가 [1, 10^5] 범위 내에 있습니다.
1 <= Node.val <= 9


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
    public int pseudoPalindromicPaths (TreeNode root) {
        return dfs(root, new HashSet<>());
    }

    private int dfs(TreeNode node, Set<Integer> numbers) {
        if (node == null) return 0;
        if (!numbers.add(node.val)) numbers.remove(node.val);
        if(node.left == null && node.right == null)
            return numbers.size() <= 1 ? 1 : 0;
        
        int left = dfs(node.left,new HashSet(numbers));
        int right = dfs(node.right,new HashSet(numbers));
        return left + right;
    }
}