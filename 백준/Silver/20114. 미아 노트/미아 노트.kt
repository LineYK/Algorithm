/*
미아 노트

시간 제한	메모리 제한
1 초	256 MB
문제
미아는 과일을 좋아하는 소녀이다.
그녀의 비밀 노트에는 과일에 대해 그녀가 수집한 정보들이 가득하다.

평소와 다를 바 없이 과일들을 잔뜩 관찰하고 기쁜 마음으로 하교하던
어느 날, 친구가 뒤에서 덮치는 바람에 실수로 비밀 노트를 물에 빠뜨리고 말았다.

다행히 노트는 건질 수 있었지만,
노트에 적어두었던 정보들이 번지고 지워져버려 일부는 알아볼 수 없게 되었다.

노트에 적힌 문자열이 번진 패턴은 일정했는데,
가령 "abc" 문자가 세로로 3글자씩, 가로로 2글자씩 번진 경우는 다음과 같았다.

aabbcc
aabbcc
aabbcc
이 패턴을 이용해 문자열을 완전히 복원할 수 있을 것 같았지만,
아쉽게도 번진 문자열의 일부는 지워진 상태였다.
너무 많이 지워져버려서 해당 자리의 문자를 유추할 수 없는 경우, 완전히 문자열을 복원하지 못할 수도 있다.

미아는 자신이 아끼는 노트가 물에 빠진 바람에 매우 속상해하고 있다.
문자열을 최대한 완전히 복원해서 미아의 기를 살려주자!

입력
첫째 줄에 원래 문자열의 길이 N, 세로로 번진 글자의 개수 H, 가로로 번진 글자의 개수 W가 주어진다. (1 ≤ N ≤ 100, 1 ≤ H ≤ 10, 1 ≤ W ≤ 10)

둘째 줄부터 H개의 줄에 걸쳐 N × W 길이의 문자열이 주어진다.
문자열은 알파벳 소문자 또는 '?'로만 이루어져 있다. '?'는 해당 자리의 문자가 지워진 경우를 뜻한다.

문자가 번진 자리에 두 개 이상의 문자가 있는 등 모순되는 경우는 입력으로 주어지지 않는다.

출력
손상되기 전의 원래 문자열을 출력한다. 복원할 수 없는 문자는 '?'로 출력한다.

예제 입력 1
3 2 2
a?????
???bcc
예제 출력 1
abc
복원할 수 없는 문자는 없다.

예제 입력 2
6 2 3
???rrruuu???ttt???
f?f?rruuu?????t???
예제 출력 2
fru?t?
원래 문자열의 4번째 문자와 6번째 문자는 복원할 수 없다.
*/

fun main() {
    val (n, h, w) = readln().split(" ").map { it.toInt() }
    val arr = Array(h) { readln() }
    var temp = arr[0]

    // Fill in the missing characters in the first string
    for (i in 1 until h) {
        for (j in temp.indices) {
            if (temp[j] == '?' && arr[i][j] != '?') {
                temp = temp.replaceRange(j..j, arr[i][j].toString())
            }
        }
    }

    val ans = StringBuilder()
    for (i in 0 until n) {
        var found = false
        for (j in i * w until i * w + w) {
            if (temp[j] != '?') {
                ans.append(temp[j])
                found = true
                break
            }
        }
        if (!found) {
            ans.append('?')
        }
    }

    println(ans.toString())
}