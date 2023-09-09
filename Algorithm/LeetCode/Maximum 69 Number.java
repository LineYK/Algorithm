// 1323. Maximum 69 Number (https://leetcode.com/problems/maximum-69-number)

class Solution {
    public int maximum69Number (int num) {
        int[] arr = new int[4];
        int res = num;

        for (int i = 0; num != 0; i++) {
            arr[i] = num%10;
            num /= 10;
        }
        for (int i = 3; i >= 0; i--) {
            if (arr[i] == 6) {
                res += 3* Math.pow(10, i);
                break;
            }
        }

        return res;
    }
}

class Solution2 {
    public int maximum69Number (int num) {
        return Integer.parseInt(("" + num).replaceFirst("6", "9"));
    }
}