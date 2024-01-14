/*
Z

시간 제한   메모리 제한
0.5 초 (추가 시간 없음)   512 MB

문제
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다.
예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

N > 1인 경우, 배열을 크기가 2^N-1 × 2^N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2N
예제 입력 1
2 3 1
예제 출력 1
11

예제 입력 2
3 7 7
예제 출력 2
63

예제 입력 3
1 0 0
예제 출력 3
0

예제 입력 4
4 7 7
예제 출력 4
63

예제 입력 5
10 511 511
예제 출력 5
262143

예제 입력 6
10 512 512
예제 출력 6
786432
*/

import java.io.*;
import java.util.*;

public class Main {

   static int N, R, C;
   static int cnt = 0;
   static StringBuilder sb = new StringBuilder();

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      R = Integer.parseInt(st.nextToken());
      C = Integer.parseInt(st.nextToken());

      int len = (int) Math.pow(2, N);

      zSearch(0, 0, len);

      System.out.print(sb);
   }

   static void zSearch(int r, int c, int len) {
      if (len == 1) {
         sb.append(cnt);
         return;
      }

      int newLen = len/2;

      if (R < r + newLen && C < c + newLen) {
         zSearch(r, c, newLen);
      }
      if (R < r + newLen && C >= c + newLen) {
         cnt += len * len / 4;
         zSearch(r, c + newLen, newLen);
      }
      if (R >= r + newLen && C < c + newLen) {
         cnt += len * len / 4 * 2;
         zSearch(r + newLen, c, newLen);
      }
      if (R >= r + newLen && C >= c + newLen) {
         cnt += len * len / 4 * 3;
         zSearch(r + newLen, c + newLen, newLen);
      }
   }
}