/*
합 구하기
 
시간 제한	메모리 제한
1 초	256 MB

문제
N개의 수 A1, A2, ..., AN이 입력으로 주어진다. 
총 M개의 구간 i, j가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 
둘째 줄에는 A1, A2, ..., AN이 주어진다. (-1,000 ≤ Ai ≤ 1,000) 
셋째 줄에는 구간의 개수 M이 주어진다. (1 ≤ M ≤ 100,000) 
넷째 줄부터 M개의 줄에는 각 구간을 나타내는 i와 j가 주어진다. (1 ≤ i ≤ j ≤ N)

출력
총 M개의 줄에 걸쳐 입력으로 주어진 구간의 합을 출력한다.

예제 입력 1 
5
10 20 30 40 50
5
1 3
2 4
3 5
1 5
4 4
예제 출력 1 
60
90
120
150
40
예제 입력 2 
3
1 0 -1
6
1 1
2 2
3 3
1 2
2 3
1 3
예제 출력 2 
1
0
-1
1
-1
0
*/


fun main() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }
    val m = readln().toInt()
    val sum = IntArray(n + 1)
    for (i in 1..n) {
        sum[i] = sum[i - 1] + arr[i - 1]
    }
    repeat(m) {
        val (i, j) = readln().split(" ").map { it.toInt() }
        println(sum[j] - sum[i - 1])
    }
}