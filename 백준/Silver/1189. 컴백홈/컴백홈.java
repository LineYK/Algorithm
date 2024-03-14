/*
컴백홈

시간 제한   메모리 제한
2 초   128 MB

문제
한수는 캠프를 마치고 집에 돌아가려 한다.
한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 그리고 한수는 집에 돌아가는 방법이 다양하다.
단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다.

      cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f
      bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde
      a...  abcd  abc.  abcd  a...  a.gh  abc.
거리 :  6     6     6     8     8    10    6
위 예제는 한수가 집에 돌아갈 수 있는 모든 경우를 나타낸 것이다. T로 표시된 부분은 가지 못하는 부분이다.
문제는 R x C 맵에 못가는 부분이 주어지고 거리 K가 주어지면 한수가 집까지도 도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다.

입력
첫 줄에 정수 R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가 공백으로 구분되어 주어진다.
두 번째부터 R+1번째 줄까지는 R×C 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.

출력
첫 줄에 거리가 K인 가짓수를 출력한다.

예제 입력 1
3 4 6
....
.T..
....
예제 출력 1
4
*/

import java.io.*;
import java.util.*;

public class Main {
   static int R, C, K;
   static char[][] map;
   static boolean[][] visited;
   static int cnt = 0;

   static final int[] X = {0, 0, 1, -1};
   static final int[] Y = {1, -1, 0, 0};

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      R = Integer.parseInt(st.nextToken());
      C = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      map = new char[R][C];
      visited = new boolean[R][C];

      for (int i = 0; i < R; i++)
         map[i] = br.readLine().toCharArray();

      visited[R-1][0] = true;
      dfs(R-1, 0, 1);

      System.out.print(cnt);
   }

   static void dfs(int r, int c, int depth) {
      if (r == 0 && c == C - 1) {
         if (depth == K) cnt++;
         return;
      }

      for (int i = 0; i < 4; i++) {
         int x = r + X[i];
         int y = c + Y[i];
         if (x < 0 || x >= R || y < 0 || y >= C) continue;

         if (!visited[x][y] && map[x][y] != 'T') {
            visited[x][y] = true;
            dfs(x, y, depth + 1);
            visited[x][y] = false;
         }
      }
   }
}
