// 206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list)

// Definition for singly-linked list.
 public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solution {
    public ListNode reverseList(ListNode head) {
        int[] nodeVal = new int[5000];
        int size = 0;

        for (ListNode node = head; node != null; node = node.next) {
            nodeVal[size++] = node.val;
        }

        ListNode res = new ListNode(nodeVal[size-1]);
        ListNode pos = res;

        for (int i = size-2; i >= 0; i--, pos = pos.next) {
           pos.next = new ListNode(nodeVal[i]);
        }

        return res;
    }
}

class Solution2 {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;

        while (cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
}