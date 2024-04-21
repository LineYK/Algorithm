/*
가장 긴 감소하는 부분 수열

시간 제한   메모리 제한
1 초   256 MB
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에
가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

예제 입력 1
6
10 30 10 20 20 10
예제 출력 1
3
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      // 수열 A의 크기 N
      int N = Integer.parseInt(br.readLine());
      // 수열 A
      int[] arr = new int[N+1];
      // dp
      int[] dp = new int[N+1];

      // 수열 A를 이루고 있는 Ai
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 1; i <= N; i++) {
         arr[i] = Integer.parseInt(st.nextToken());
      }

      // dp[i] = i번째 수열까지의 가장 긴 감소하는 부분 수열의 길이
      for (int i = 1; i <= N; i++) {
         // i번째 수열까지의 가장 긴 감소하는 부분 수열의 길이는 1
         dp[i] = 1;
         for (int j = 1; j < i; j++) {
            // i번째 수열이 j번째 수열보다 작고, dp[i]가 dp[j]보다 작거나 같을 때
            if (arr[i] < arr[j] && dp[i] <= dp[j]) {
               dp[i] = dp[j] + 1;
            }
         }
      }

      // dp배열에서 가장 큰 값이 가장 긴 감소하는 부분 수열의 길이
      int max = 0;
      // dp배열에서 가장 큰 값 찾기
      for (int i = 1; i <= N; i++) {
         max = Math.max(max, dp[i]);
      }

      System.out.print(max);
   }
}