/*
쉬운 최단거리
 
시간 제한	메모리 제한
1 초	128 MB
문제
지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라.

문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.

입력
지도의 크기 n과 m이 주어진다. n은 세로의 크기, m은 가로의 크기다.(2 ≤ n ≤ 1000, 2 ≤ m ≤ 1000)

다음 n개의 줄에 m개의 숫자가 주어진다. 0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 입력에서 2는 단 한개이다.

출력
각 지점에서 목표지점까지의 거리를 출력한다. 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.

예제 입력 1 
15 15
2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1 0 0 0
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
예제 출력 1 
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
11 12 13 14 15 16 17 18 19 20 0 0 0 0 25
12 13 14 15 16 17 18 19 20 21 0 29 28 27 26
13 14 15 16 17 18 19 20 21 22 0 30 0 0 0
14 15 16 17 18 19 20 21 22 23 0 31 32 33 34
*/

import java.io.*;
import java.util.*;

public class Main {
   static int n, m;
   static final int[] X = {0, 0, -1, 1};
   static final int[] Y = {-1, 1, 0, 0};
   static int[][] map;
   static int[][] visited;
   static int[] start;

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());
      
      map = new int[n][m];
      visited = new int[n][m];
      start = new int[2];
      
      for (int i = 0; i < n; i++) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < m; j++) {
          map[i][j] = Integer.parseInt(st.nextToken());
          if (map[i][j] == 2) {
            start[0] = i;
            start[1] = j;
          }
        }
      }
      
      bfs();
      
       
      StringBuilder sb = new StringBuilder();

      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
              if(visited[i][j] == 0 && map[i][j] == 1) visited[i][j] = -1;
              sb.append(visited[i][j]).append(' ');
          }
          sb.append('\n');
      }

       
      System.out.print(sb);
   }
   
   static void bfs() {
     Queue<int[]> q = new ArrayDeque<>();
     q.offer(start);
     while(!q.isEmpty()) {
       int[] node = q.poll();
       int cnt = visited[node[0]][node[1]];
       for (int i = 0; i < 4; i++) {
         int x = node[0] + X[i];
         int y = node[1] + Y[i];
         if (x < 0 || x >= n || y < 0 || y >= m) continue;
         if (visited[x][y] == 0 && map[x][y] == 1) {
             visited[x][y] = cnt + 1;
             q.offer(new int[]{x, y});
         }
       }
     }
     
   }

}