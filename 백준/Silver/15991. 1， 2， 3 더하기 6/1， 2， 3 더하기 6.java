/*
1, 2, 3 더하기 6
 
시간 제한	메모리 제한
1 초 (추가 시간 없음)	512 MB

문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 단, 합은 대칭을 이루어야 한다.

1+1+1+1
1+2+1
2+2

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 100,000보다 작거나 같다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.

예제 입력 1 
3
4
7
10
예제 출력 1 
3
6
20

*/

import java.io.*;
import java.util.*;

public class Main {
  
   public static void main(String[] args) throws IOException {
    
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      int t = Integer.parseInt(br.readLine());
      long[] dp = new long[100001];
      
      dp[1] = 1;
      dp[2] = 2;
      dp[3] = 2;
      dp[4] = 3;
      dp[5] = 3;
      dp[6] = 6;
      
      for (int i = 7; i < dp.length; i++) {
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6]) % 1_000_000_009;
      }
      
      StringBuilder sb = new StringBuilder();
      
      for (int i = 0; i < t; i++) {
        int n = Integer.parseInt(br.readLine());
        sb.append(dp[n]).append('\n');
      }
      
      System.out.print(sb);
   }
}
