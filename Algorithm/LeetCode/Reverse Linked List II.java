// 92. Reverse Linked List II (https://leetcode.com/problems/reverse-linked-list-ii)


// Definition for singly-linked list.
public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {

    /**
     * 배열에 각 위치 노드저장
     * 시작과 끝을 만들어 리버스할 새 노드를 배열에서 값 찾아 새로 만듦
     * 끝에 다음 값 연결
     * 앞에 값 있으면 거기에 다음 새 링크드 노드 연결 후 리턴
     * 없으면 만든 노드 리턴
     */
    public ListNode reverseBetween(ListNode head, int left, int right) {
        
        ListNode[] nodes = new ListNode[500];
        ListNode pos = head;

        for (int i = 0; pos != null; i++) {
            nodes[i] = pos;
            pos = pos.next;
        }

        ListNode start = new ListNode(nodes[right-1].val);
        ListNode end = start;

        for (int i = right-2; i >= left-1; i--){
            end.next = new ListNode(nodes[i].val);
            end = end.next;
        }
        end.next = nodes[right];

        if(left >= 2){
            nodes[left-2].next = start;
            return head;
        }
            
        return start; 
    }
}

class Solution2 {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0); 
        dummy.next = head;
        ListNode prev = dummy; 
        
        for(int i = 0; i < left - 1; i++)
            prev = prev.next; 
        
        ListNode curr = prev.next; 
        
        for(int i = 0; i < right - left; i++){
            ListNode forw = curr.next; 
            curr.next = forw.next;
            forw.next = prev.next;
            prev.next = forw;
        }
        return dummy.next;
    }
}