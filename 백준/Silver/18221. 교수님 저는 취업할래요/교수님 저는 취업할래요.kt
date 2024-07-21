/*
교수님 저는 취업할래요

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	1630	727	598	44.165%
문제
성규는 학점이 높고 알고리즘도 잘 다루는 편이라 매년 알고리즘 대회에 나가 수상을 해오곤 한다. 성규의 꿈은 대학교 4학년 칼졸업을 하고 나서 좋은 대기업에 취직하여 빨리 돈을 버는 것이다.

어느 날, 성규는 전공 수업을 들으러 강의실에 가서 책을 펴고 앉았다. 이 때 교수님이 수업을 시작하시기 전에 한 말씀 하셨다.

교수님: "음... 여기서 내가 눈 여겨 봐온 학생이 있는데... 그래, 성규야. 너 내 랩실에 들어올 생각 없니? 나와 함께 알고리즘에 대한 논문이나 써보자꾸나."

성규는 큰일이다 싶었다. 성규는 졸업하고 싶었다. 대답을 할 생각이 떠오르기 전에 먼저 도망가야겠다는 생각이 들어버렸다!

강의실에는 가로로 N 행, 세로로 N 열, 총 N × N 개의 책상이 있으며, 위쪽에서부터 R 번째 행, 왼쪽에서부터 C 번째 열에 있는 책상의 위치를 (R, C)로 표현한다. 각 책상 자리는 비어있거나, 성규가 아닌 학생 혹은 성규가 앉아있거나, 교수님이 위치해 있다.

도망가는 데 성공하려면, 성규와 교수님의 거리가 5 이상이면서, 교수님과 성규를 꼭짓점으로 하는 축에 평행한 직사각형 안에, 교수님을 제지해줄 성규가 아닌 학생이 세 명 이상 있어야 한다.
단, 교수님과 성규가 같은 행 혹은 같은 열의 책상에 앉아있다면 교수님과 성규를 잇는 선분 상에 성규가 아닌 학생이 세 명 이상 있어야 한다.

이때, 책상 (a, b)와 책상 (c, d) 간의 거리는
$\sqrt{(a-c)^2 + (b-d)^2}$로 정의한다.

성규는 도망가다가 잡히는 것이 최악이라 판단되어, 도망갈 수가 없는 환경이면 순순히 대학원생의 길로 들어서려고 한다. 이런 성규를 위해 확실히 도망갈 수 있는지 알려주는 프로그램을 작성하자.

입력
입력의 첫 번째 줄에 자연수 N(7 ≤ N ≤ 1,000) 이 주어진다.

두 번째 줄부터 N개의 각 줄에 0, 1, 2, 5 중 하나의 숫자가 공백으로 구분되어 N개씩 주어진다.

N개의 줄 중 R번째 줄의 C번째 숫자가 d라는 것은 다음과 같은 의미를 가진다:

d = 0: 책상 (R, C)는 빈 자리이다.
d = 1: 책상 (R, C)는 성규가 아닌 학생이 앉아있다.
d = 2: 책상 (R, C)는 성규가 앉아있다.
d = 5: 책상 (R, C)는 교수님이 앉아있다.
성규와 교수님은 겹치지 않으며, 각각 정확히 한 자리에만 앉아있다.

출력
첫 번째 줄에 성규가 교수님에게서 도망칠 수 있으면 1, 그렇지 못하면 0을 출력한다.

예제 입력 1
7
0 5 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 1 0 0
0 0 0 0 0 2 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
예제 출력 1
1
예제 입력 2
9
0 5 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0
0 0 2 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
예제 출력 2
0
예제 입력 3
10
0 5 0 0 0 0 1 0 0 0
0 1 0 0 0 0 1 0 0 0
0 0 0 0 0 0 2 0 0 0
0 0 1 1 0 0 1 0 0 0
1 0 0 0 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
예제 출력 3
1
*/

import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val board = Array(n) { IntArray(n) }
    var gyu: Pair<Int, Int>? = null
    var professor: Pair<Int, Int>? = null

    for (i in 0 until n) {
        for (j in 0 until n) {
            board[i][j] = scanner.nextInt()
            when (board[i][j]) {
                2 -> gyu = Pair(i, j)
                5 -> professor = Pair(i, j)
            }
        }
    }

    fun check(x1: Int, y1: Int, x2: Int, y2: Int): Boolean {
        var cnt = 0
        val xMin = minOf(x1, x2)
        val xMax = maxOf(x1, x2)
        val yMin = minOf(y1, y2)
        val yMax = maxOf(y1, y2)

        for (y in yMin..yMax) {
            for (x in xMin..xMax) {
                if (board[y][x] == 1) {
                    cnt++
                }
            }
        }

        if (cnt >= 3 && (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= 25) {
            if (x1 == x2 || y1 == y2) {
                return true
            } else {
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= 25) {
                    return true
                }
            }
        }
        return false
    }

    if (gyu != null && professor != null) {
        val (y1, x1) = gyu
        val (y2, x2) = professor
        val answer = check(x1, y1, x2, y2)
        println(if (answer) 1 else 0)
    }
}

