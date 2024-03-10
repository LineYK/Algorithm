/*
BABBA

시간 제한	메모리 제한
1 초	128 MB
문제
상근이는 길을 걷다가 신기한 기계를 발견했다. 기계는 매우 매우 큰 화면과 버튼 하나로 이루어져 있다.

기계를 발견했을 때, 화면에는 A만 표시되어져 있었다. 버튼을 누르니 글자가 B로 변했다.
한 번 더 누르니 BA로 바뀌고, 그 다음에는 BAB, 그리고 BABBA로 바뀌었다.
상근이는 화면의 모든 B는 BA로 바뀌고, A는 B로 바뀐다는 사실을 알게되었다.

버튼을 K번 눌렀을 때, 화면에 A와 B의 개수는 몇 개가 될까?

입력
첫째 줄에 K (1 ≤ K ≤ 45)가 주어진다.

출력
첫째 줄에 A의 개수와 B의 개수를 공백으로 구분해 출력한다.

예제 입력 1
1
예제 출력 1
0 1
예제 입력 2
4
예제 출력 2
2 3
예제 입력 3
10
예제 출력 3
34 55

0 1
1 1
1 2 BAB
2 3 BABBA
3 5 BABBABAB
*/

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int K = Integer.parseInt(br.readLine());

		int[][] dp = new int[46][2];

		dp[1][0] = 0;
		dp[1][1] = 1;

		dp[2][0] = 1;
		dp[2][1] = 1;

		for (int i = 3; i <= K; i++) {
			dp[i][0] = dp[i-1][1];
			dp[i][1] = dp[i-1][1] + dp[i-2][1];
		}

		System.out.print(dp[K][0] + " " + dp[K][1]);
	}
}
