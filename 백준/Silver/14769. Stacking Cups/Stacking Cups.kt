/*
스태킹 컵

시간 제한 메모리 제한
1 초 512 MB

문제
로봇을 위한 컵 쌓기 모듈을 프로그래밍하고 있습니다.
이 로봇에는 컵의 반경과 색상을 정확하게 파악할 수 있는 여러 센서가 장착되어 있습니다.
문제는 센서 입력을 처리하는 로봇의 핵심 루틴에 결함이 있어 색상 센서의 결과가 반경 이후에 루틴에
도착하면 반경이 두 배가 된다는 것입니다.

예를 들어 반경이 5단위인 빨간색 컵의 경우 모듈은 “red 5” 또는 “red 10” 메시지 중 하나를 수신합니다.

각각 다른 컵을 설명하는 핵심 루틴의 메시지 목록이 주어졌을 때,
컵을 가장 작은 것부터 가장 큰 것까지 순서대로 배열할 수 있나요?

입력
입력 파일의 첫 번째 줄에는 컵의 개수인 정수 N이 들어 있습니다(1 ≤ N ≤ 20).
다음 N 줄에는 각각 “color radius” 또는 “diameter color”으로 두 개의 토큰이 포함됩니다.
컵 R의 반지름은 1000보다 작은 양의 정수입니다. 컵 C의 색은 최대 20자 길이의 비어 있지 않은 영문 소문자 문자열입니다.
모든 컵은 크기와 색상이 모두 다릅니다.

출력
컵의 색상을 반경이 커지는 순서대로 한 줄에 한 색씩 출력합니다.

예제 입력 1
3
red 10
10 blue
green 7
예제 출력 1
blue
green
red

*/

fun main() {
    val n = readln().toInt()
    val cups = mutableListOf<Pair<String, Int>>()
    repeat(n) {
        val (a, b) = readln().split(" ")
        if (a.toIntOrNull() != null) { // 숫자가 앞에 있는 경우
            cups.add(Pair(b, a.toInt() / 2))
        } else { // 숫자가 뒤에 있는 경우
            cups.add(Pair(a, b.toInt()))
        }
    }
    cups.sortBy { it.second }
    cups.forEach {
        println(it.first)
    }
}