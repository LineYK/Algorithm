/*
모든 순열

시간 제한   메모리 제한
1 초   256 MB
문제
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.

예제 입력 1
3
예제 출력 1
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

import java.io.*;
import java.util.*;

public class Main {

   static int[] arr;
   static boolean[] visited;
   static int N;
   static StringBuilder res = new StringBuilder();

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      N = Integer.parseInt(br.readLine());
      arr = new int[N];
      visited = new boolean[N];

      dfs(0);

      System.out.print(res);
   }

   static void dfs(int depth) {
      if (depth == N) {
         for (int n : arr) {
            res.append(n).append(' ');
         }
         res.append('\n');
         return;
      }

      for (int i = 0; i < N; i++) {
         if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i + 1;
            dfs(depth + 1);
            visited[i] = false;
         }
      }
   }
}