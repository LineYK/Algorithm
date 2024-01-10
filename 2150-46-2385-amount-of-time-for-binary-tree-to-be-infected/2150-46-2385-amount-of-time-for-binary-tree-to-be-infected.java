/**
2385. 바이너리 트리가 감염되는 데 걸리는 시간

고유한 값을 가진 이진 트리의 루트와 시작 값이 정수로 주어집니다. 
0분이 되면 시작 값이 0인 노드부터 감염이 시작됩니다.

매 분마다 다음과 같은 경우 노드가 감염됩니다:

노드가 현재 감염되지 않은 상태입니다.
노드가 감염된 노드에 인접한 경우.
전체 트리가 감염되는 데 필요한 시간(분)을 반환합니다.

예제 1:
입력: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
설명: 다음 노드가 감염되었습니다:
- 분 0: 노드 3
- 1분: 노드 1, 10, 6
- 분 2: 노드 5
- 3분: 노드 4
- 4분: 노드 9 및 2
전체 트리가 감염되는 데 4분이 걸리므로 4를 반환합니다.

예제 2:
입력: root = [1], start = 1
Output: 0
설명: 트리가 감염되었습니다: 분 0에서 트리의 유일한 노드가 감염되었으므로 0을 반환합니다.
 

제약 조건:
트리의 노드 수는 [1, 105] 범위에 있습니다.
1 <= Node.val <= 105
각 노드에는 고유한 값이 있습니다.
값이 start인 노드가 트리에 존재합니다.


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
    HashMap<TreeNode, List<TreeNode>> graph;
    Set<TreeNode> visited;
    Queue<TreeNode> queue;
    TreeNode target;

    public int amountOfTime(TreeNode root, int start) {
        graph = new HashMap();
        visited = new HashSet();
        queue = new ArrayDeque<TreeNode>();

        createGraph(root, start);

        queue.offer(target);
        visited.add(target);

        int time = 0;

        while(!queue.isEmpty()) {
            int size = queue.size();
            while(size-- > 0) {
                TreeNode cur = queue.poll();

                for (TreeNode node : graph.get(cur)){
                    if (!visited.contains(node)) {
                        queue.offer(node);
                        visited.add(node);
                    }
                }
            }
            time++;
        }

        return time - 1;
    }

    void createGraph(TreeNode root, int start) {
        if(root == null) return;
        
        if(!graph.containsKey(root))
            graph.put(root, new ArrayList<TreeNode>());
        
        if(root.left != null) {
            if(!graph.containsKey(root.left))
                graph.put(root.left, new ArrayList<TreeNode>());
            
            graph.get(root).add(root.left);
            graph.get(root.left).add(root);
        }
        
       if(root.right != null) {
            if(!graph.containsKey(root.right))
                graph.put(root.right, new ArrayList<TreeNode>());
            
            graph.get(root).add(root.right);
            graph.get(root.right).add(root);
        } 
        
        if(root.val == start)
            target = root;
        
        createGraph(root.left, start);
        createGraph(root.right, start);
    }
}