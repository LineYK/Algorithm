/*
CA번 - 하루 피부과
시간 제한	메모리 제한
1 초	1024 MB
문제
2023년, 하루는 피부과를 개원해 여드름 전용 레이저인 HARU-LASER를 이용해 사람들의 여드름을 치료해 주고 있다.

여드름의 모양을 나타내는 이차함수는
$f(x) = ax^2+bx+c$로 정의되어 있고, 레이저에 설정되어 있는 일차함수를
$g(x) = dx+e$로 정의할 때, 레이저의 세기는
$\displaystyle{\int_{x_1}^{x_2} \{ f(x) - g(x) \}\mathrm{d}x}$로 정의된다.

이때,
$x_1$,
$x_2$는 여드름의 양 끝의
$x$좌표를 나타낸 것이며,
$f(x)$와
$g(x)$의 정의역은
$(-\infty, \infty)$이다.

피부과를 개원한 지 얼마 안 된 하루는 레이저의 세기를 잘 계산하지 못한다. 여러분이 하루를 대신해 레이저의 세기를 계산해 주자.

입력
첫 번째 줄에
$x_1$,
$x_2$가 공백으로 구분되어 주어진다.

두 번째 줄에 이차함수
$f(x)$와 일차함수
$g(x)$의 계수
$a$,
$b$,
$c$,
$d$,
$e$가 공백으로 구분되어 주어진다.

입력되는 모든 수는 정수이며, 레이저의 세기가 절댓값이
$10^{9}$ 이하인 정수가 되도록 하는 입력만이 주어진다.

출력
첫 번째 줄에 레이저의 세기를 출력한다.

제한
 
$-30 \leq x_1 < x_2 \leq 30$ 
 
$-30 \leq a,b,c,d,e \leq 30$ 
 
$a,d \neq 0$ 
 
$a$는
$3$의 배수
 
$b,d$는
$2$의 배수
예제 입력 1
0 1
3 4 2 8 3
예제 출력 1
-2

예제 입력 2
-3 3
-15 -4 5 -2 -5
예제 출력 2
-210
*/

import java.io.*;
import java.util.*;

public class Main {
	static int a, b, c, d, e;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int x1 = Integer.parseInt(st.nextToken());
		int x2 = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());

		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		System.out.print(fun(x2) - fun(x1));

	}

	static int fun(int x) {
		int x2 = a;
		int x1 = b - d;
		int n = c - e;

		return (int) (x2 * Math.pow(x, 3) / 3 + x1 * Math.pow(x, 2) / 2 + n * x);
	}
}