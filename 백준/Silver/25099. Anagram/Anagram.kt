/*
애너그램

시간 제한 메모리 제한
4초 (추가 시간 없음) 256MB

문제
첫 번째 단어의 글자를 순서대로 바꾸어 두 번째 단어를 얻을 수 있다면 두 단어는 아나그램입니다.
아나그램의 예로는 "listen"와 "silent"이 있습니다.

각 단어가 소문자로 구성된 단어 목록이 주어집니다.
여러분의 목표는 목록의 앞부분에 이미 애너그램이 나타난 단어를 삭제하여 이 목록을 필터링하는 것입니다.

입력
첫 번째 줄에는 다음이 포함됩니다.
n, 목록의 길이입니다. 그 뒤에
n 줄이 이어지며, 각 줄은 하나의 단어를 포함합니다.

출력
애너그램이 없는 단어 목록을 한 줄에 한 단어씩 출력합니다. 단어는 입력에 주어진 것과 같은 순서로 나타나야 합니다.

제한
1 ≤ n ≤ 10^5
모든 문자는 영어 알파벳 소문자입니다.
단어의 길이는 다음을 초과하지 않습니다.
100.

예제 입력 1
5
listen
santa
satan
silent
cat
예제 출력 1
listen
santa
cat
*/


fun main() {
    val n = readln().toInt()
    val anagrams = mutableSetOf<String>()
    val res = mutableListOf<String>()

    for (i in 0 until n) {
        val word = readln()
        val sortedWord = word.toCharArray().sorted().joinToString("")
        if (sortedWord !in anagrams) {
            res.add(word)
            anagrams.add(sortedWord)
        }
    }
    
    println(res.joinToString("\n"))
}