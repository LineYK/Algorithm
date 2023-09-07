// 725. Split Linked List in Parts (https://leetcode.com/problems/split-linked-list-in-parts)


// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] res = new ListNode[k];
        int size = 0;
        ListNode pos = head;
        while (pos != null) {
            size++;
            pos = pos.next;
        }
        int div = size / k < 0 ? 1 : size / k;
        int remain = size % k;

        pos = head;
        ListNode prev = null;
        for (int i = 0; pos != null; i++, remain--) {
            res[i] = pos;
            for (int j = 0; j < div + (remain > 0 ? 1 : 0); j++) {
                prev = pos;
                pos = pos.next;
            }
            prev.next = null;
        }

        return res;
    }
}