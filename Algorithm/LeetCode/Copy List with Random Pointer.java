// 138. Copy List with Random Pointer (https://leetcode.com/problems/copy-list-with-random-pointer/)

import java.util.*;

// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}


class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        Node res = new Node(head.val);
        Map<Node, Integer> map = new HashMap<>();
        Node[] resNodes = new Node[1001];

        Node oriPos = head;
        Node resPos = res;
        for (int i = 0; oriPos != null; i++) {   
            map.put(oriPos, i);
            resNodes[i] = resPos;

            if (oriPos.next != null)
                resPos.next = new Node(oriPos.next.val);
            
            oriPos = oriPos.next;
            resPos = resPos.next;
        }

        oriPos = head;
        resPos = res;

        while (oriPos != null) {
            if (map.get(oriPos.random) != null){
                int index = map.get(oriPos.random);
                resPos.random = resNodes[index];
            }
            oriPos = oriPos.next;
            resPos = resPos.next;
        }

        return res;
    }
}
