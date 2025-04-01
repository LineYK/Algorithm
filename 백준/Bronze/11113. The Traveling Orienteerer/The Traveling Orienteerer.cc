/*
The Traveling Orienteerer
 
시간 제한	메모리 제한	
1 초	256 MB	

문제
Lasse is organizing the orienteering world championship in Trondheim in 2008. Since he has been running in Bymarka for decades, he has a lot of route proposals. He must find a route with just the right length, but he doesn’t have time to measure them all by running through the control points in order, as he is too busy parallelizing code. The job is therefore given to Ola, who he thinks spends too much time with schoolwork.

As Ola is slightly less interested in orienteering, he figures out a more time-saving way of measuring the length of all the routes. He brings his GPS, visits all the points of all the routes in the most convenient order, and goes home early to do the rest of the job on his computer.

입력
The first line of input gives 1 ≤ n ≤ 1000, the total number of control points. Then follow n lines giving their coordinates, with two floating-point numbers xi and yi, with 0.0 ≤ xi, yi ≤ 10000.0. The number of routes is then given by 1 ≤ m ≤ 100. Each route is defined by first a line with 2 ≤ p ≤ 17, the number of control points (including start and goal), and then a line with p indexes 0 ≤ i < n, identifying them.

출력
For each test case output the total track distance, rounded, with no decimals.

예제 입력 1 
5
0.0 0.0
1000.0 1000.0
123.45 0.0
3475.43 7765.4
4325.9865 13.0
2
2
0 1
4
3 1 4 0
예제 출력 1 
1414
14999
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<double, double>> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        
        vector<int> route(p);
        for(int j = 0; j < p; j++){
            cin >> route[j];
        }
        
        double total_distance = 0.0;
        for(int j = 0; j < p - 1; j++){
            double x1 = points[route[j]].first;
            double y1 = points[route[j]].second;
            double x2 = points[route[j+1]].first;
            double y2 = points[route[j+1]].second;
            
            double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            total_distance += distance;
        }
        
        cout << round(total_distance) << "\n";
    }
    
    return 0;
}