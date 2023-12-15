/*
1436. 목적지 도시

경로 배열이 주어지며, 경로[i] = [cityAi, cityBi]는 cityAi에서 cityBi로 가는 직접 경로가 존재함을 의미합니다. 목적지 도시, 즉 다른 도시로 나가는 경로가 없는 도시를 반환합니다.

경로 그래프는 루프가 없는 선을 형성하므로 목적지 도시가 정확히 하나라는 것이 보장됩니다.

예제 1:
입력: 경로 = [["런던","뉴욕"],["뉴욕","리마"],["리마","상파울루"]]
Output: "상파울루" 
설명: "런던" 도시에서 출발하여 목적지인 "상파울루" 도시에 도착합니다. 여행은 다음과 같이 구성됩니다: "런던" -> "뉴욕" -> "리마" -> "상파울루".

예제 2:
입력: 경로 = [["B","C"],["D","B"],["C","A"]]
Output: "A"
설명: 가능한 모든 트립을 반환합니다: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
분명히 목적지 도시는 "A"입니다.

예 3:
입력: 경로 = [["A","Z"]]
출력: "Z"
 
제약 조건:

1 <= paths.length <= 100
경로[i].길이 == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
모든 문자열은 영문 소문자 및 대문자와 공백 문자로 구성됩니다.
*/

class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> set = new HashSet<>();

        for (List<String> p : paths) {
            set.add(p.get(0));
        }

        String res = "";

        for (List<String> p : paths) {
            if (!set.contains(p.get(1))) {
                res = p.get(1);
            }
        }

        return res;
    }
}