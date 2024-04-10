/*
1로 만들기 2

시간 제한   메모리 제한
0.5 초   512 MB

문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다.
정답이 여러 가지인 경우에는 아무거나 출력한다.

예제 입력 1
2
예제 출력 1
1
2 1
예제 입력 2
10
예제 출력 2
3
10 9 3 1
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringBuilder sb = new StringBuilder();

      int N = Integer.parseInt(br.readLine());

      int[] dp = new int[N + 1];
      int[] before = new int[N + 1];

      dp[1] = 0;
      before[1] = -1;

      for (int i = 2; i <= N; i++) {
         dp[i] = dp[i - 1] + 1;
         before[i] = i - 1;

         if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
         }

         if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
         }
      }

      sb.append(dp[N]).append('\n');
      for (int i = N; i != -1; i = before[i])
         sb.append(i).append(' ');
      
      System.out.print(sb);
   }
}

