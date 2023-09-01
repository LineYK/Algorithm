// 1688. Count of Matches in Tournament (https://leetcode.com/problems/count-of-matches-in-tournament)

class Solution {
    public int numberOfMatches(int n) {
        int res = 0;
        while (n != 0) {
            if (n % 2 == 1)
                res += 1;
            n /= 2;
            res += n;
        }
        return res - 1;
    }

    public int numberOfMatches2(int n) {
        return n - 1;
    }
}

    
        
              
        
    