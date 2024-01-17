/*
이항 계수 2
 
시간 제한	메모리 제한
1 초	256 MB

문제
자연수 
\(N\)과 정수 
\(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
\(N\)과 
\(K\)가 주어진다. 
(1 ≤ \(N\) ≤ 1,000, 0 ≤ \(K\) ≤ \(N\))

출력
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] nums = br.readLine().split(" ");
    int	n = Integer.parseInt(nums[0]);
    int k = Integer.parseInt(nums[1]);
    
    int[][] dp = new int[1001][1001];
    
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
      dp[i][i] = 1;
    }
    
	  for (int i = 2; i <= n; i++) {
	    for (int j = 1; j <= k; j++) {
	      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
	    }
	  }
	  
		System.out.print(dp[n][k]);
	}

}
