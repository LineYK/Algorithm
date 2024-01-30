/*
LCS
 
시간 제한	메모리 제한
0.1 초 (하단 참고)	256 MB

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4
*/

import java.io.*;
import java.util.*;

public class Main {
   
   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      String str1 = br.readLine();
      String str2 = br.readLine();
      
      int[][] dp = new int[str1.length()+1][str2.length()+1];
      
      for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
          if (str1.charAt(i-1) == str2.charAt(j-1)) 
            dp[i][j] = dp[i-1][j-1] + 1;
          else
            dp[i][j] = Math.max(dp[i][j-1],dp[i-1][j]);
        }
      }
      System.out.print(dp[str1.length()][str2.length()]);
   }
}