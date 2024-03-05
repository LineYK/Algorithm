/*
카드 놓기

시간 제한   메모리 제한
1 초   256 MB

문제
상근이는 카드 n(4 ≤ n ≤ 10)장을 바닥에 나란히 놓고 놀고있다.
각 카드에는 1이상 99이하의 정수가 적혀져 있다.
상근이는 이 카드 중에서 k(2 ≤ k ≤ 4)장을 선택하고,
가로로 나란히 정수를 만들기로 했다. 상근이가 만들 수 있는 정수는 모두 몇 가지일까?

예를 들어, 카드가 5장 있고, 카드에 쓰여 있는 수가 1, 2, 3, 13, 21라고 하자.
여기서 3장을 선택해서 정수를 만들려고 한다. 2, 1, 13을 순서대로 나열하면 정수 2113을 만들 수 있다.
또, 21, 1, 3을 순서대로 나열하면 2113을 만들 수 있다. 이렇게 한 정수를 만드는 조합이 여러 가지 일 수 있다.

n장의 카드에 적힌 숫자가 주어졌을 때,
그 중에서 k개를 선택해서 만들 수 있는 정수의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이, 둘째 줄에 k가 주어진다. 셋째 줄부터 n개 줄에는 카드에 적혀있는 수가 주어진다.

출력
첫째 줄에 상근이가 만들 수 있는 정수의 개수를 출력한다.

예제 입력 1
4
2
1
2
12
1
예제 출력 1
7

예제 입력 2
6
3
72
2
12
7
2
1
예제 출력 2
68
*/

import java.io.*;
import java.util.*;

public class Main {

   static String[] arr;
   static boolean[] visited;
   static int n, k;
   static Set<String> set = new HashSet<>();

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      n = Integer.parseInt(br.readLine());
      k = Integer.parseInt(br.readLine());

      arr = new String[n];
      visited = new boolean[n];

      for (int i = 0; i < n; i++)
         arr[i] = br.readLine();

      dfs(0, "");

      System.out.print(set.size());
   }

   static void dfs(int depth, String s) {
      if (depth == k) {
         set.add(s);
         return;
      }

      for (int i = 0; i < n; i++) {
         if (!visited[i]) {
            visited[i] = true;
            dfs(depth + 1, s + arr[i]);
            visited[i] = false;
         }
      }
   }
}