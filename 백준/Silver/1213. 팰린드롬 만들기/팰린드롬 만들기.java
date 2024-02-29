/*
팰린드롬 만들기

시간 제한   메모리 제한
2 초   128 MB
문제
임한수와 임문빈은 서로 사랑하는 사이이다.

임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데,
임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다.
만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

예제 입력 1
AABB
예제 출력 1
ABBA

예제 입력 2
AAABB
예제 출력 2
ABABA

예제 입력 3
ABACABA
예제 출력 3
AABCBAA

예제 입력 4
ABCD
예제 출력 4
I'm Sorry Hansoo
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int[] alpha = new int[26];

      for (char c : br.readLine().toCharArray())
         alpha[c - 'A']++;

      int odd = 0;
      for (int i : alpha)
         if (i % 2 != 0) odd++;

      if (odd > 1) {
         System.out.print("I'm Sorry Hansoo");
         return;
      }

      StringBuilder res = new StringBuilder();
      StringBuilder sb = new StringBuilder();

      for (int i = 0; i < alpha.length; i++)
         for (int j = 0; j < alpha[i] / 2; j++)
            sb.append((char)('A' + i));

      res.append(sb);
      String end = sb.reverse().toString();

      sb = new StringBuilder();
      for (int i = 0; i < alpha.length; i++) {
         if (alpha[i] % 2 == 1)
            sb.append((char)('A' + i));
      }
      res.append(sb).append(end);

      System.out.print(res);
   }
}