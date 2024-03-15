/*
근손실

시간 제한	메모리 제한
1 초	256 MB

문제
웨이트 트레이닝을 좋아하는 어떤 대학원생은, 현재 3대 운동 중량 500의 괴력을 소유하고 있다.
다만, 하루가 지날 때마다 중량이 K만큼 감소한다.
예를 들어 K=4일 때, 3일이 지나면 중량이 488로 감소하게 된다.
따라서 운동을 하지 않고, 가만히 있다면 매일매일 중량이 감소할 뿐이다.

다행히도 이 대학원생은 N개의 서로 다른 운동 키트를 가지고 있다.
이 대학원생은 하루에 1개씩의 키트를 사용하며, 매일 어떤 키트를 사용할 지는 마음대로 결정할 수 있다.
운동 키트들은 각각의 중량 증가량을 가지고 있으며, 사용할 때마다 즉시 중량이 증가하게 된다.
이 때 몇몇 운동 키트들의 중량 증가량이 같을 수 있으나, 서로 다른 운동 키트로 간주한다.
각각의 운동 키트는 N일 동안 한 번씩만 사용할 수 있다.

대학원생은 운동 기간동안 항상 중량이 500 이상으로 유지가 되도록 N일간의 운동 플랜을 세우고자 한다.
1일차부터 N일차까지의 모든 기간동안, 어떤 시점에서라도 중량이 500보다 작아지지 않도록 해야 한다.

예를 들어 N=3, K=4일 때, 각 운동 키트의 중량 증가량이 다음과 같다고 가정하자.

이 때 1번, 3번, 2번 순서대로 운동 키트를 적용한다고 해보자.
이 경우 운동 1일차에 대학원생은 중량이 3만큼 증가하지만 그와 동시에 하루에 중량이 4만큼 감소하기 때문에,
1일이 지난 이후에 중량은 499가 된다. 따라서 조건을 만족하지 못한다.

반면에 3번, 1번, 2번 순서대로 운동 키트를 적용한다고 해보자.
그러면 1일차부터 운동을 모두 마친 날까지의 모든 시점에 대하여 항상 중량이 500이상이 된다.

N개의 운동 키트에 대한 정보가 주어졌을 때, N일간 하루에 1개씩의 운동 키트를 사용하는 모든 경우 중에서,
운동 기간동안 항상 중량이 500 이상이 되도록 하는 경우의 수를 출력하는 프로그램을 작성하시오.

위 예시에서는 모든 경우 중에서 총 4가지 경우가 조건을 만족한다.

입력
첫째 줄에 자연수 N과 K가 공백을 기준으로 구분되어 주어진다. (1 ≤ N ≤ 8, 1 ≤ K ≤ 50)
둘째 줄에 각 운동 키트의 중량 증가량 A가 공백을 기준으로 구분되어 주어진다. (1 ≤ A ≤ 50)

출력
N일 동안 N개의 운동 키트를 사용하는 모든 경우 중에서,
운동 기간동안 항상 중량이 500 이상이 되도록 하는 경우의 수를 출력한다.

예제 입력 1
3 4
3 7 5
예제 출력 1
4
*/

import java.io.*;
import java.util.*;

public class Main {
	static int N, K;
	static int[] arr;
	static boolean[] visited;
	static int cnt = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		arr = new int[N];
		visited = new boolean[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		dfs(500, 0);

		System.out.print(cnt);
	}

	static void dfs(int sum, int depth) {
		if (depth == N) {
			cnt++;
			return;
		}

		for (int i = 0; i < N; i++) {
			if (!visited[i] && sum + arr[i] - K >= 500) {
				visited[i] = true;
				dfs(sum + arr[i] - K, depth + 1);
				visited[i] = false;
			}

		}
	}
}
