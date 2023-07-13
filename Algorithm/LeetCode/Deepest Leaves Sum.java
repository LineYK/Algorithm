// 1302. Deepest Leaves Sum (https://leetcode.com/problems/deepest-leaves-sum)

import java.util.LinkedList;

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

    int sum = 0;
    int maxLevel = 0;

    public int deepestLeavesSum(TreeNode root) {
        if (root == null) return 0;
        calculateSumAtLevel(root, 0);
        return sum;
    }

    private void calculateSumAtLevel(TreeNode root, int level) {
        if (root == null) return;
        if (level > maxLevel) {
            sum = 0;
            maxLevel = level;
        } 
        if (level == maxLevel) {
            sum += root.val;
        }
        calculateSumAtLevel(root.left, level + 1);
        calculateSumAtLevel(root.right, level + 1);
    }
}

class Solution2 {

    public int deepestLeavesSum(TreeNode root) {
        int res = 0, i;
        LinkedList<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            for (i = q.size() - 1, res = 0; i >= 0; --i) {
                TreeNode node = q.poll();
                res += node.val;
                if (node.right != null) q.add(node.right);
                if (node.left != null) q.add(node.left);
            }
        }
        return res;
    }

}

/** LinkedList
 * Collection 프레임워크의 일부이며 java.util 패키지에 소속되어 있다.
 * 데이터가 연속된 위치에 저장되지 않고 모든 데이터가 데이터 값과 주소 값을 별도로 가지고 있다.
 * 각 데이터는 노드라 불리며 배열에서 자주 삽입, 삭제가 이루어지는 경우 용이하여 ArrayList보다 선호된다.
 * 하지만 ArrayList보다 검색은 느리다.
 * 
    * add(int index, Object) : index에 데이터를 추가
    * add(Object) : index를 생략한 경우 가장 마지막에 데이터가 추가 실패시 예외 발생
    * size() : 현재 크키 반환
    * poll() : 맨 앞에 있는 요소를 반환하고, 해당 요소를 제거
    * peek() : 맨 앞에 있는 요소를 반환
    * offer() : 가장 마지막에 데이터가 추가 실패시 false 반환
 * 
 */