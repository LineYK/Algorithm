/*
차이를 최대로

시간 제한   메모리 제한
1 초   256 MB
문제
N개의 정수로 이루어진 배열 A가 주어진다.
이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다.
둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

예제 입력 1
6
20 1 15 8 4 10
예제 출력 1
62
*/

import java.io.*;
import java.util.*;

public class Main {

   static int n;
   static int[] arr;
   static int[] nums;
   static boolean[] visited;
   static int res = Integer.MIN_VALUE;

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      n = Integer.parseInt(br.readLine());

      StringTokenizer st = new StringTokenizer(br.readLine());

      nums = new int[n];
      arr = new int[n];
      visited = new boolean[n];

      for (int i = 0; i < n; i++)
         nums[i] = Integer.parseInt(st.nextToken());
      Arrays.sort(nums);

      dfs(0);

      System.out.print(res);
   }

   static void dfs(int depth) {
      if (depth == n) {
         int sum = 0;
         for (int i = 1; i < n; i++) {
            sum += Math.abs(arr[i-1] - arr[i]);
         }

         res = Math.max(res, sum);
         return;
      }

      int prev = 0;

      for (int i = 0; i < n; i++) {
         if (!visited[i] && nums[i] != prev) {
            arr[depth] = nums[i];
            prev = arr[depth];
            visited[i] = true;
            dfs(depth + 1);
            visited[i] = false;
         }
      }
   }
}