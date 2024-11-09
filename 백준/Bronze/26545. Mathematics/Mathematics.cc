/*
Mathematics 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	1024 MB	3513	2929	2810	83.931%
문제
A mathematician has stolen your calculator! Luckily, you know how to code and can write a program that adds together numbers. Write a program that adds together a list of integers.

입력
The first line will contain a single integer n that indicates the number of integers to add together. The next n lines will each contain one integer. Your task is to write a program that adds all of the integers together.

출력
Output the resulting integer. The output should be one line containing one integer value.

예제 입력 1 
3
1
2
3
예제 출력 1 
6
*/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << sum;
    
    return 0;
}