import kotlin.math.absoluteValue

/*
터치스크린 키보드

시간 제한	메모리 제한
1 초	128 MB
문제
요즘 사람들은 터치 스크린 키보드를 사용한다.
하지만, 터치 스크린은 버튼과 버튼 사이의 간격이 작고, 버튼의 크기가 작기 때문에 오타가 너무 많이 난다.

상근이는 오타를 줄여주기 위해서 맞춤법 검사 프로그램을 만들었다.
이 프로그램은 이름은 맞춤법 검사이지만, 실제로는 오타만 검사한다.

맞춤법 검사 프로그램은 사용자가 단어를 입력하면,
프로그램이 가지고 있는 올바른 단어 목록 중 길이가 같으면서 비슷한 단어를 추천해 준다.
이때, 가장 비슷한 단어를 제일 먼저 보여준다.

터치 스크린 키보드는 다음과 같이 생겼다.

qwertyuiop
asdfghjkl
zxcvbnm
사용자가 단어를 입력하면, 각 단어와의 거리를 계산할 수 있다.
단어와 단어의 거리는 키보드 상에서 문자끼리의 거리의 합이다.
문자와 문자의 거리는 키보드에서 가로로 떨어져 있는 거리와 세로로 떨어져 있는 거리를 더하면 된다.
예를 들어, w를 입력했을 때, e와의 거리는 1, z와의 거리는 3이다.
또, icpc와 ifpv의 거리는 3이다. 거리가 가까울 수록 비슷한 단어이다.

입력
첫째 줄에 테스트 케이스의 개수 t (0 < t < 20)가 주어진다.
각 테스트 케이스의 첫째 줄에는 사용자가 입력한 단어와 프로그램이 가지고 있는 단어의 개수 l이 주어진다. (0 < l ≤ 10)
다음 l개의 줄에는 단어가 주어진다. 이 단어는 사용자가 입력한 단어와 길이가 모두 같고, 알파벳 소문자로만 이루어져 있다.
길이는 최대 10,000글자이다. 또, 같은 단어가 중복되어서 등장하지 않는다.

출력
각 테스트 케이스에 대해서, 추천하는 단어를 거리순으로 정렬한 뒤 단어와 거리를 출력한다.
만약, 두 단어가 같은 거리를 거지고 있다면, 사전 순으로 정렬한다.

예제 입력 1
2
ifpv 3
iopc
icpc
gcpc
edc 5
wsx
edc
rfv
plm
qed
예제 출력 1
icpc 3
gcpc 7
iopc 7
edc 0
rfv 3
wsx 3
qed 4
plm 17
*/

fun main() {
    val keyboard = arrayOf(
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    )

    val t = readln().toInt()
    val sb = StringBuilder()
    repeat(t) {
        val (word, l) = readln().split(" ")
        val words = mutableMapOf<String, Int>()
        repeat(l.toInt()) {
            val w = readln()
            words[w] = w.zip(word).sumBy { (a, b) ->
                val (x1, y1) = keyboard.find { a in it }!!.indexOf(a) to keyboard.indexOfFirst { a in it }
                val (x2, y2) = keyboard.find { b in it }!!.indexOf(b) to keyboard.indexOfFirst { b in it }
                (x1 - x2).absoluteValue + (y1 - y2).absoluteValue
            }
        }
        words.toList().sortedWith(compareBy({ it.second }, { it.first })).forEach { (w, d) ->
            sb.append("$w $d\n")
        }
    }
    print(sb)
}