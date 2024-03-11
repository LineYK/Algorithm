/*
제곱수의 합

시간 제한   메모리 제한
2 초   128 MB

문제
어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다.
예를 들어 11=3^2+1^2+1^2(3개 항)이다. 이런 표현방법은 여러 가지가 될 수 있는데,
11의 경우 11=2^2+2^2+1^2+1^2+1^2(5개 항)도 가능하다. 이 경우,
수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다.
또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로,
11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.

주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

출력
주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

예제 입력 1
7
예제 출력 1
4
예제 입력 2
1
예제 출력 2
1
예제 입력 3
4
예제 출력 3
1
예제 입력 4
11
예제 출력 4
3
예제 입력 5
13
예제 출력 5
2
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int N = Integer.parseInt(br.readLine());

      int[] dp = new int[N+1];

      for (int i = 1; i <= N; i++) {
         dp[i] = i;
         for (int j = 1; j*j <= i; j++) {
            if (dp[i] > dp[i - j*j] + 1)
               dp[i] = dp[i - j*j] + 1;
         }
      }


      System.out.print(dp[N]);
   }
}
