// 1656. Design an Ordered Stream (https://leetcode.com/problems/design-an-ordered-stream)

import java.util.*;

class OrderedStream {
    int ptr;
    String[] res;
    

    public OrderedStream(int n) {
        ptr = 0;
        res = new String[n];
    }
    
    public List<String> insert(int idKey, String value) {
        List<String> list = new ArrayList<>();

        res[idKey-1] = value;
        while(ptr < res.length && res[ptr] != null) {
            list.add(res[ptr]);
            ptr++;
        }

        return list;
    }
}