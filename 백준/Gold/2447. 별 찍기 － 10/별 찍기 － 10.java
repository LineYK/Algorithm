/*
별 찍기 - 10

시간 제한   메모리 제한
1 초   256 MB
문제
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때,
크기 N의 패턴은 N×N 정사각형 모양이다.

크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

***
* *
***
N이 3보다 클 경우,
크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다.
예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

입력
첫째 줄에 N이 주어진다.
N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3^k이며, 이때 1 ≤ k < 8이다.

출력
첫째 줄부터 N번째 줄까지 별을 출력한다.

예제 입력 1
27
예제 출력 1
***************************
* ** ** ** ** ** ** ** ** *
***************************
***   ******   ******   ***
* *   * ** *   * ** *   * *
***   ******   ******   ***
***************************
* ** ** ** ** ** ** ** ** *
***************************
*********         *********
* ** ** *         * ** ** *
*********         *********
***   ***         ***   ***
* *   * *         * *   * *
***   ***         ***   ***
*********         *********
* ** ** *         * ** ** *
*********         *********
***************************
* ** ** ** ** ** ** ** ** *
***************************
***   ******   ******   ***
* *   * ** *   * ** *   * *
***   ******   ******   ***
***************************
* ** ** ** ** ** ** ** ** *
***************************
*/

import java.io.*;
import java.util.*;

public class Main {
   static char[][] pattern;

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());

      pattern = new char[n][n];

      star(0, 0, n, false);

      StringBuilder sb = new StringBuilder();

      for (char[] p : pattern) {
         for (char c : p)
            sb.append(c);
         sb.append('\n');
      }

      System.out.print(sb);
   }

   static void star(int x, int y, int n, boolean blank) {

      if (blank) {
         for (int i = x; i < x + n; i++)
            for (int j = y; j < y + n; j++)
               pattern[i][j] = ' ';
         return;
      }

      if (n == 1) {
         pattern[x][y] = '*';
         return;
      }

      int size = n/3;
      int cnt = 0;
      for (int i = x; i < x + n ; i+= size) {
         for (int j = y; j < y + n; j+= size) {
            cnt++;
            star(i, j, size, cnt == 5);
         }
      }
   }

}