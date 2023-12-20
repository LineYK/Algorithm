/*
소수 찾기

시간 제한 메모리 제한
2 초	128 MB
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다.
다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

예제 입력 1
4
1 3 5 7
예제 출력 1
3
*/

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int res = 0;

		int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		for (int n : arr) {
			if (n < 2) continue;
			boolean check = true;

			for (int i = 2; i < n; i++) {
				if (n % i == 0) {
					check = false;
					break;
				}
			}
			if (check) res++;
		}

		System.out.print(res);
	}

}