/*
나이트의 이동
 
시간 제한	메모리 제한	
1 초	256 MB
문제
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?



입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.

예제 입력 1 
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
예제 출력 1 
5
28
0
*/

import java.io.*;
import java.util.*;

public class Main {
  
  static int[] X = {-2, -2, -1, -1, 1, 1, 2, 2};
  static int[] Y = {-1, 1, -2, 2, -2, 2, -1, 1};
  static StringBuilder sb = new StringBuilder();
  
   public static void main(String[] args) throws IOException {
    
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      int t = Integer.parseInt(br.readLine());
      
      for (int i = 0; i < t; i++) {
        int l = Integer.parseInt(br.readLine());
        int[] start = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] goal = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        bfs(l, start, goal);
      }
      
      System.out.print(sb);
   }
   
   static void bfs(int l, int[] start, int[] goal) {
     int cnt = 0;
     int[][] map = new int[l][l];
     boolean[][] visited = new boolean[l][l];
     Queue<int[]> que = new ArrayDeque<>();
     que.offer(start);
     
     while(!que.isEmpty()) {
       int[] knight = que.poll();
       visited[knight[0]][knight[1]] = true;
       
       for (int i = 0; i < 8; i++) {
         int x = knight[0] + X[i];
         int y = knight[1] + Y[i];
         
         if (x < 0 || x >= l || y < 0 || y >= l) continue;
         
         if (!visited[x][y]) {
           que.offer(new int[]{x, y});
           map[x][y] = map[knight[0]][knight[1]] + 1;
           visited[x][y] = true;
         }
       }
       
     }
     
     sb.append(map[goal[0]][goal[1]]).append('\n');
   }
}
