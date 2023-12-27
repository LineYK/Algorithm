/*
2×n 타일링 2

시간 제한   메모리 제한
1 초   256 MB

문제
2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

예제 입력 1
2
예제 출력 1
3

예제 입력 2
8
예제 출력 2
171

예제 입력 3
12
예제 출력 3
2731
*/
import java.io.*;

public class Main {
   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int[] dp = new int[n+2];

      dp[0] = 1;
      dp[1] = 3;

      for (int i = 2; i < n; i++)
         dp[i] = (2 * dp[i-2] + dp[i-1]) % 10007;

      System.out.print(dp[n-1]);
   }
} 