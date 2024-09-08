/*
문자 빈도

시간 제한 메모리 제한
1 초 (추가 시간 없음) 1024 MB

문제
영어에서 가장 흔한 자음은 R, T, N, S, L이고 가장 흔한 모음은 E, A, I입니다.
가장 흔한 글자를 찾는 것은 확실히 재미있습니다.

단어 세트가 주어지면 각 위치에서 가장 많이 나오는 문자를 찾으세요.
즉, 모든 단어를 고려할 때 위치 1에서 가장 빈번한 글자, 모든 단어를 고려할 때 위치 2에서 가장 빈번한 글자 등을 찾습니다.
특정 위치에서 가장 빈번한 문자가 두 개 이상인 경우(즉, 해당 위치에서 최대값이 동점인 경우)
해당 문자를 알파벳 순서로 인쇄합니다.

입력
첫 번째 입력 줄에는 단어 수를 나타내는 정수 n(1 ≤ n ≤ 20)이 포함됩니다.
다음 n개의 입력 줄에는 각각 단어가 포함됩니다. 각 단어는 1~30개의 소문자를 포함하며
첫 번째 열에서 시작한다고 가정합니다.

출력
샘플 출력에 설명된 형식에 따라 각 위치와 해당 위치에서 가장 많이 나오는 문자를 출력합니다.
각 출력 줄은 숫자로 시작하고 바로 뒤에 콜론(':'), 공백, 문자로 이어집니다.
출력 줄에 문자가 여러 개 있는 경우에는 정확히 하나의 공백으로 구분합니다.

예제 입력 1
5
this
is
an
example
ink
예제 출력 1
1: i
2: n
3: a i k
4: m s
5: p
6: l
7: e
예제 입력 2
3
this
is
longlonglong
예제 출력 2
1: i l t
2: h o s
3: i n
4: g s
5: l
6: o
7: n
8: g
9: l
10: o
11: n
12: g
*/


fun main() {
    val n = readln().toInt()
    val words = List(n) { readln() }
    val map = mutableMapOf<Int, MutableMap<Char, Int>>()

    for (word in words) {
        for (i in word.indices) {
            val m = map.getOrPut(i) { mutableMapOf() }
            m[word[i]] = m.getOrDefault(word[i], 0) + 1
        }
    }

    for ((i, m) in map) {
        val max = m.values.maxOrNull()!!
        val chars = m.filterValues { it == max }.keys.sorted()
        println("${i + 1}: ${chars.joinToString(" ")}")
    }
}