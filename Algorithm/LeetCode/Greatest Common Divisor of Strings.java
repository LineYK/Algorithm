// 1071. Greatest Common Divisor of Strings (https://leetcode.com/problems/greatest-common-divisor-of-strings)

class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2+str1)) return "";

        int gcdVal = gcd(str1.length(), str2.length());
        return str2.substring(0, gcdVal);
    }

    public static int gcd(int p, int q) {
        if (q == 0) return p;
        return gcd(q, p % q);
    }
}

/**
 * 유클리드 호제법 생각안나서 삽질함
 */