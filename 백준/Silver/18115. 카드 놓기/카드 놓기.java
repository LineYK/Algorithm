/*
카드 놓기
 
시간 제한   메모리 제한
2 초 (추가 시간 없음)   1024 MB
문제
수현이는 카드 기술을 연습하고 있다. 
수현이의 손에 들린 카드를 하나씩 내려놓아 바닥에 쌓으려고 한다. 
수현이가 쓸 수 있는 기술은 다음 3가지다.

1.제일 위의 카드 1장을 바닥에 내려놓는다.
2.위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
3.제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
수현이는 처음에 카드 N장을 들고 있다. 
카드에는 1부터 N까지의 정수가 중복되지 않게 적혀 있다. 
기술을 N번 사용하여 카드를 다 내려놓았을 때, 
놓여 있는 카드들을 확인했더니 위에서부터 순서대로 1, 2, …, N이 적혀 있었다!

놀란 수현이는 처음에 카드가 어떻게 배치되어 있었는지 궁금해졌다. 
처음 카드의 상태를 출력하여라.

입력
첫 번째 줄에는 N (1 ≤ N ≤ 10^6)이 주어진다.

두 번째 줄에는 길이가 N인 수열 A가 주어진다. Ai가 x이면, 
i번째로 카드를 내려놓을 때 x번 기술을 썼다는 뜻이다. Ai는 1, 2, 3 중 하나이며, An은 항상 1이다.

출력
초기 카드의 상태를 위에서부터 순서대로 출력하여라.

예제 입력 1 
5
1 1 1 1 1
예제 출력 1 
5 4 3 2 1
예제 입력 2 
5
2 3 3 2 1
예제 출력 2 
1 5 2 3 4
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int n = Integer.parseInt(br.readLine());
      Deque<Integer> deque = new ArrayDeque<>();
      
      String[] strArr = br.readLine().split(" ");
      StringBuilder sb = new StringBuilder();
       
      for(int i = 1; i <= n; i++) {
          switch (strArr[n-i]) {
              case "1" : 
                  deque.addFirst(i);
                  break;
              case "2" : 
                  int top = deque.removeFirst();
                  deque.addFirst(i);
                  deque.addFirst(top);
                  break;
              case "3" :
                  deque.addLast(i);
                  break;
          }
      }
      while(!deque.isEmpty()) {
        sb.append(deque.removeFirst()).append(' ');
      }
      System.out.print(sb);
   }

}