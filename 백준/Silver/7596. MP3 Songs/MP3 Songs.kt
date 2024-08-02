/*
MP3 노래 다국어
 
시간 제한 메모리 제한
1초 128MB

문제
수는 자신의 MP3 플레이어를 좋아하지만 셔플 모드가 트랙을 무작위로 재생하는 것이 싫습니다. 
그녀는 순서와 패턴을 좋아하기 때문에 MP3 플레이어의 곡이 알파벳 순서로 재생되기를 원합니다. 
이 문제에서는 곡 이름을 알파벳 순서로 정렬하여 Sue를 도와야 합니다. 

입력
입력은 여러 시나리오로 구성되며, 각 시나리오는 정렬이 필요한 음악 트랙의 수인 단일 양의 정수 n으로 시작됩니다(1 < n <= 200). 입력의 마지막 줄은 0 하나이며, 이 시나리오는 처리하지 않아야 합니다.

각 시나리오는 n개의 줄로 구성되며, 각 줄에는 곡명이 포함됩니다. 한 줄에 250자를 초과할 수 없습니다. 
각 이름은 알파벳 문자로 시작됩니다. 

출력
출력은 시나리오 번호(첫 번째는 1)가 한 줄에 단독으로 표시됩니다. 그 다음에는 입력 목록의 곡명을 알파벳 순서로 정렬하여 한 줄에 이름 하나씩 n줄로 표시합니다. 대소문자는 무시해야 합니다. 

Translated with DeepL.com (free version)
예제 입력 1
10
Forever
Take A Bow
Always On My Mind
Lollipop
Love In This Club
No Air
Sweet About Me
Party People
Mercy
American Boy
8
Partita
Air on a 'G' string
Sinfonia in D
Jesu, joy of man's desiring
Arioso
Violin Concerto in A Minor
Brandenburg Concerto 2
Concerto for 2 violins
0
예제 출력 1
1
Always On My Mind
American Boy
Forever
Lollipop
Love In This Club
Mercy
No Air
Party People
Sweet About Me
Take A Bow
2
Air on a 'G' string
Arioso
Brandenburg Concerto 2
Concerto for 2 violins
Jesu, joy of man's desiring
Partita
Sinfonia in D
Violin Concerto in A Minor
*/


fun main() {
    var count = 1
    while (true) {
        val n = readln().toInt()
        if (n == 0) break
        val list = mutableListOf<String>()
        repeat(n) {
            list.add(readln())
        }
        println(count++)
        println(list.sorted().joinToString("\n"))
    }
}