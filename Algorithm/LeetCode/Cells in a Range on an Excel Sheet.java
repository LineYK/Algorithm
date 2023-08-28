// 2194. Cells in a Range on an Excel Sheet (https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet)

import java.util.*;

class Solution {
    public List<String> cellsInRange(String s) {
        List<String> res = new ArrayList<>();

        for (char c = s.charAt(0); c <= s.charAt(3); c++) {
            for(char n = s.charAt(1); n <= s.charAt(4); n++){
                res.add(new StringBuilder().append(c).append(n).toString());
            }
        }
        return res;
    }
}
