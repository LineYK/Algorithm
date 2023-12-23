/*
1496. 경로 교차로

각각 북쪽, 남쪽, 동쪽, 서쪽으로 한 단위씩 이동하는 것을 나타내는 문자열 경로가 주어지며, 경로[i] = 'N', 'S', 'E' 또는 'W'가 주어집니다. 2D 평면의 원점(0, 0)에서 시작하여 경로로 지정된 경로를 따라 걷습니다.

경로가 어느 지점에서든 교차하는 경우, 즉 이전에 방문한 적이 있는 위치에 있는 경우 참을 반환합니다. 그렇지 않으면 false를 반환합니다.

 
예제 1:
입력: 경로 = "NES"
출력: false 
설명: 경로가 어떤 지점을 두 번 이상 교차하지 않는지 확인합니다.

예제 2:
입력: 경로 = "NESWW"
출력: true
설명: 경로가 원점을 두 번 방문합니다: 경로가 원점을 두 번 방문한다는 것을 알 수 있습니다.
 

제약 조건:

1 <= path.length <= 10^4
경로[i]는 'N', 'S', 'E' 또는 'W' 중 하나입니다.
*/

class Solution {
	public boolean isPathCrossing(String path) {
		Set<String> set = new HashSet<>();
		set.add("0 0");

		int x = 0;
		int y = 0;

		for (char c : path.toCharArray()) {
			switch (c) {
				case 'N' -> y += 1;
				case 'S' -> y -= 1;
				case 'E' -> x -= 1;
				default -> x += 1;
			}

			if (!set.add(x + " " + y)) return true;
		}

		return false;
	}
}