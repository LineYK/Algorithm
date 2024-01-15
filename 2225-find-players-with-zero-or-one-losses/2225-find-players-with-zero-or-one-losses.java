/*
2225. 패배가 0 또는 1건인 플레이어 찾기

matches 정수 배열이 주어지며, matches[i] = [승자, 패자]는 경기에서 승자 플레이어가 패자 플레이어를 이긴 것을 나타냅니다.

여기서 크기가 2인 리스트 답을 반환합니다:

answer[0]은 경기에서 패하지 않은 모든 플레이어의 목록입니다.
answer[1]은 정확히 한 경기에서 패배한 모든 플레이어의 리스트입니다.
두 리스트의 값은 점점 더 큰 순서로 반환되어야 합니다.

참고:
적어도 한 경기 이상 플레이한 플레이어만 고려해야 합니다.
테스트 케이스는 두 경기의 결과가 같지 않도록 생성됩니다.


예시 1:
입력: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
설명합니다:
플레이어 1, 2, 10은 어떤 경기에서도 패배하지 않았습니다.
플레이어 4, 5, 7, 8은 각각 한 경기에서 패했습니다.
플레이어 3, 6, 9는 각각 두 번의 경기에서 패했습니다.
따라서 answer[0] = [1,2,10] 및 answer[1] = [4,5,7,8]이 됩니다.

예제 2:
입력: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
설명:
플레이어 1, 2, 5, 6은 어떤 경기에서도 패하지 않았습니다.
플레이어 3과 4는 각각 두 번의 경기에서 패했습니다.
따라서 answer[0] = [1,2,5,6], answer[1] = [] 입니다.


제약 조건:
1 <= matches.length <= 105
matches[i].length == 2
1 <= 승자, 패자 <= 105
winneri != loseri
모든 match[i]는 고유합니다.
*/

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        ans.add(new ArrayList<>());
        int player[][] = new int[100001][2];
        
        for (int i = 0; i < matches.length; i++){ 
            int winner = matches[i][0];
            int losser = matches[i][1];
            player[winner][0]++;
            player[losser][1]++;
        }
    
        for (int i = 1; i < player.length; i++) {
            if (player[i][0] > 0 && player[i][1] == 0) 
                ans.get(0).add(i);
            else if (player[i][0] >= 0 && player[i][1]== 1) 
                ans.get(1).add(i);
        }
        return ans;
    }
}