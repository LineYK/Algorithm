/*
최대공약수와 최소공배수

시간 제한 메모리 제한
1 초	128 MB
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다.
이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,
둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

예제 입력 1
24 18
예제 출력 1
6
72
*/

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int b = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());

		int g = gcd(a, b);

		StringBuilder sb = new StringBuilder();
		sb.append(g).append('\n').append(a*b/g);

		System.out.print(sb);
	}

	static int gcd(int a, int b) {
		if (b == 0) return a;
		return gcd(b, a%b);
	}

}