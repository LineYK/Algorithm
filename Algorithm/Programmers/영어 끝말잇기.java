// 영어 끝말잇기 (https://school.programmers.co.kr/learn/courses/30/lessons/12981)

import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] res = new int[]{0,0};

        char first = words[0].charAt(0);
        Set<String> usedWords = new HashSet<>();
        
        for(int i = 0; i < words.length; i++) {
            if (words[i].charAt(0) != first || usedWords.contains(words[i])) {
                res[0] = i%n + 1;
                res[1] = i/n + 1; 
                break;
            }
            usedWords.add(words[i]);
            first = words[i].charAt(words[i].length()-1);
        }
        return res;
    }
}