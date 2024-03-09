/*
쉬운 계단 수

시간 제한   메모리 제한
1 초   256 MB

문제
45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력 1
1
예제 출력 1
9

예제 입력 2
2
예제 출력 2
17
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int N = Integer.parseInt(br.readLine());

      long[][] dp = new long[N+1][10];

      for (int i = 1; i < 10; i++)
         dp[1][i] = 1;

      for (int i = 2; i <= N; i++) {
         for (int j = 0; j < 10; j++) {
            if (j == 0)
               dp[i][0] = dp[i-1][1] % 1_000_000_000;
            else if (j == 9)
               dp[i][9] = dp[i - 1][8] % 1_000_000_000;
            else
               dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1_000_000_000;
         }
      }

      long res = Arrays.stream(dp[N]).sum();

      System.out.print(res % 1_000_000_000);
   }
}
