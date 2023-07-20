// 151. Reverse Words in a String (https://leetcode.com/problems/reverse-words-in-a-string)

import java.util.*;
import java.util.stream.Collectors;


class Solution {
    public String reverseWords(String s) {
        String[] splitArr = s.trim().split("\\s+");
        List<String> strList = Arrays.asList(splitArr);
        Collections.reverse(strList);
        return strList.stream().collect(Collectors.joining(" "));
    }
}

/** \\s+
 * \s+는 정규식 패턴으로, 하나 이상의 공백 문자를 의미 
 * 여기서 \s는 공백 문자를, +는 하나 이상의 연속된 문자를 나타낸다.
 */