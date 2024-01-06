/*
1235. 작업 스케줄링의 최대 이익

시작 시간[i]부터 끝 시간[i]까지 모든 작업이 완료되어 
이익[i]의 이익을 얻도록 예약된 작업이 n개 있습니다.

시작 시간, 종료 시간 및 이익 배열이 주어지면, 
시간 범위가 겹치는 하위 집합에 두 개의 작업이 없도록 취할 수 있는 최대 이익을 반환합니다.

시간 X에 끝나는 작업을 선택하면 
시간 X에 시작되는 다른 작업을 시작할 수 있습니다.
 
예제 1:
입력: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
설명: 선택된 하위 집합은 첫 번째와 네 번째 작업입니다. 
시간 범위 [1-3]+[3-6] , 수익은 120 = 50 + 70입니다.

예제 2:
입력: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
설명: 선택된 하위 집합은 첫 번째, 네 번째, 다섯 번째 작업입니다. 
얻은 이익은 150 = 20 + 70 + 60입니다.

예제 3:
입력: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

제약 조건:
1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4
*/

class Solution {
     class Job {
        int start, end, profit;
        
        public Job(int s, int e, int p) {
            start = s;
            end = e;
            profit = p;
        }
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        Job[] jobs = new Job[profit.length];
        for (int i = 0; i < startTime.length; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }

        int dp[] = new int [jobs.length];
        Arrays.sort(jobs, (a, b) -> a.end - b.end);

        dp[0] = jobs[0].profit;
        for (int i = 1; i < jobs.length; i++){
            dp[i] = Math.max(jobs[i].profit, dp[i-1]);
            for(int j = i-1; j >= 0; j--){
                if(jobs[j].end <= jobs[i].start){
                    dp[i] = Math.max(dp[i], jobs[i].profit + dp[j]);
                    break;
                }
            }
        }
        int max = Integer.MIN_VALUE;
        for (int val : dp) {
            max = Math.max(val, max);
        }
        return max;
    }
    
}