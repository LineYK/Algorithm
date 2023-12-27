/*
XORXORXOR

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
0.2 초 (추가 시간 없음)	512 MB	3028	1589	1410	58.264%
문제
세 수 A, B, C를 입력 받은 다음, ( ( ( ( A XOR B ) XOR B ) XOR B ) … ) XOR B 형태로 연산을 C회 했을 때의 결과값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 주어진다. (0 < A, B, C ≤ 109)

출력
첫째 줄에 계산된 결과를 출력한다.

예제 입력 1
13 3 1
예제 출력 1
14
*/
import java.io.*;
import java.util.*;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());


		for (int i = 0; i < C; i++)
			A ^= B;

		System.out.print(A);

	}

}