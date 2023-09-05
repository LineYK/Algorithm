// 141. Linked List Cycle (https://leetcode.com/problems/linked-list-cycle)

import java.util.*;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> nodes = new HashSet<>();

        while (head != null) {
            if (!nodes.add(head))
                return true;

            head = head.next;
        }
        return false;
    }

    public boolean hasCycle2(ListNode head) {
        if (head == null)
            return false;
        ListNode walker = head;
        ListNode runner = head;

        while (runner.next != null && runner.next.next != null) {
            walker = walker.next;
            runner = runner.next.next;

            if (walker == runner)
                return true;
        }
        return false;
    }
}