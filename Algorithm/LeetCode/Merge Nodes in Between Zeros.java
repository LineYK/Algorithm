// 2181. Merge Nodes in Between Zeros (https://leetcode.com/problems/merge-nodes-in-between-zeros)

import java.util.LinkedList;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        int sum = 0;
        ListNode ans = null;
        ListNode target = null;
        LinkedList<ListNode> q = new LinkedList<>();
        q.add(head);
        while(!q.isEmpty()) {
            ListNode node = q.poll();
            if (node.val == 0) {
                if(ans == null){
                    ans = new ListNode();
                    target = ans;
                }
                else {
                    target.val = sum;
                    if (node.next != null) {
                        target = target.next = new ListNode();
                    }
                }
                sum = 0;
            }
            else sum += node.val;
            if (node.next != null) {
                q.add(node.next);
            }
        }
        return ans;
    }

    public ListNode mergeNodes2(ListNode head) {
    ListNode curr, root = new ListNode();
	curr = root;
    int sum = 0;
    while(head!=null){
        if(head.val==0 && sum!=0){
            curr.next = new ListNode(sum);
            curr = curr.next;
            sum = 0;
        }
        sum+=head.val;
        head = head.next;
    }
    return root.next;
   }
}