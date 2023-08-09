// 2807. Insert Greatest Common Divisors in Linked List (https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/)

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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode firNode = head;
        ListNode secNode = firNode.next;
        while(secNode != null) {
            ListNode gcdNode = new ListNode(gcd(firNode.val, secNode.val), secNode);
            firNode.next = gcdNode;
            firNode = gcdNode.next;
            secNode = secNode.next;
        }

        return head;
    }

    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
}