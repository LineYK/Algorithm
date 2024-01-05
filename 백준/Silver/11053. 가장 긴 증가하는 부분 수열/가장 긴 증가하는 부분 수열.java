/*
가장 긴 증가하는 부분 수열

문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1 
6
10 20 10 30 20 50
예제 출력 1 
4
*/


import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int A = Integer.parseInt(br.readLine());
        int[] arr = new int[A];
        int[] dp = new int[A];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < A; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i =0; i < A; i++){
          for(int j = i-1; j >=0; j--){
            if (arr[i] > arr[j])
              dp[i] = (dp[i] < dp[j] + 1) ? dp[j] + 1 : dp[i];
          }
        }
        
        int max = 0;
        for(int n : dp) {
          max = Math.max(max, n);
        }
        
        System.out.print(max+1);
    }

}


