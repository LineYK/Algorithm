/*
단계 수

시간 제한 메모리 제한
1초 128MB

문제
평면의 점 (0,0)에서 시작하여 그림과 같이 음수가 아닌 정수 0,1,2,...를 모두 썼습니다.
예를 들어, 점 (1,1), (2,0), (3,1)에 각각 1, 2, 3을 썼고 이 패턴이 계속되고 있습니다.

한 점 (x, y)의 좌표를 읽고 그 점에 쓰여진 수 (있는 경우)를 쓰는 프로그램을 작성하시오.
입력의 (x, y) 좌표는 0...5000 범위에 있습니다.

입력
입력의 첫 번째 줄은 이 문제에 대한 테스트 케이스의 수인 N입니다.
다음 N개의 줄에는 각각 한 점의 좌표 (x, y)를 나타내는 x와 y가 있습니다.

출력
입력의 각 점에 대해 해당 지점에 쓰여진 숫자를 쓰거나 숫자가 없으면 “No Number”을 씁니다.

예제 입력 1
3
4 2
6 6
3 4
예제 출력 1
6
12
No Number

*/

fun main() {
    val N = readln().toInt()
    val sb = StringBuilder()

    repeat(N) {
        val (x, y) = readln().split(" ").map { it.toInt() }

        if (x == y) {
            sb.append(x + y - x % 2).append("\n")
        } else if (x == y + 2) {
            sb.append(x + y - x % 2).append("\n")
        } else {
            sb.append("No Number").append("\n")
        }
    }
    println(sb)
}