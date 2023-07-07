// 771. Jewels and Stones (https://leetcode.com/problems/jewels-and-stones/)

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int count = 0;
        for (char stone : stones.toCharArray()) {
            if (jewels.indexOf(stone) != -1) count++;
        }
        return count;
    }
}

/** String.toCharArray()
 * java.lang.String 클래스 
 * 문자열을 char 타입의 배열로 변환하는 메소드
 */