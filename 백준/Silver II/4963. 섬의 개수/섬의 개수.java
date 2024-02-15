/*
섬의 개수
 
시간 제한	메모리 제한	
1 초	128 MB

문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. 

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

예제 입력 1 
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
예제 출력 1 
0
1
1
3
1
9
*/

import java.io.*;
import java.util.*;

public class Main {
  
  static int w, h;
  static int[][] map;
  static boolean[][] visited;
  static int[] X = {0, 0, -1, -1, -1, 1, 1, 1};
  static int[] Y = {-1, 1, -1, 0, 1, -1, 0, 1};
  static StringBuilder sb = new StringBuilder();
  
   public static void main(String[] args) throws IOException {
    
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      while (true) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        
        if (w == 0 && h == 0) break;
        
        int cnt = 0;
        map = new int[h][w];
        visited = new boolean[h][w];
        
        for (int i = 0; i < h; i++) {
          st = new StringTokenizer(br.readLine());
          for (int j = 0; j < w; j++) {
            map[i][j] = Integer.parseInt(st.nextToken());
          }
        }
        
        for (int i = 0; i < h; i++) 
          for (int j = 0; j < w; j++)
            if (map[i][j] == 1 && !visited[i][j]) {
              bfs(i, j);
              cnt++;
            }
        
        sb.append(cnt).append('\n');
      }
      
      System.out.print(sb);
   }
   
   static void bfs(int x, int y) {
     Queue<int[]> que = new ArrayDeque<>();
     que.offer(new int[]{x, y});
     visited[x][y] = true;
     
     while (!que.isEmpty()) {
       int[] node = que.poll();
       
       for (int i = 0; i < 8; i++) {
         int nx = node[0] + X[i];
         int ny = node[1] + Y[i];
         
         if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         
         if (map[nx][ny] == 1 && !visited[nx][ny]) {
           que.offer(new int[]{nx, ny});
           visited[nx][ny] = true;
         }
       }
     }
     
   }

}
