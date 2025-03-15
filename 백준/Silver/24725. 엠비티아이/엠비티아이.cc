/*
엠비티아이
 
시간 제한	메모리 제한	
1 초 (추가 시간 없음)	1024 MB (추가 메모리 없음)
문제
Myers-Briggs Type Indicator (MBTI) is an introspective self-report questionnaire indicating differing psychological preferences in how people perceive the world and make decisions.

MBTI divides human personality into 16 types and each type consists of 4 alphabets.

The first letter represents extroversion (E) or introversion (I), indicating how they gain their energy.
The second letter represents intuition (N) or sensation (S), indicating how new information is understood and interpreted.
The third letter represents emotions (F) or thinking (T), indicating how they make decisions.
The last letter represents perception (P) or judgment (J), indicating lifestyle preferences how they organize their time.
There are 16 types of MBTI because a total of four alphabets are selected according to each description (e.g. ENFP, ISTP, ENTJ, etc.)

One day, you find an alphabet board while going to the laboratory. As you are too obsessed with MBTI, you start looking for how many MBTI types are on the board. If the four horizontal, vertical, or diagonal letters on the board are one of the types of MBTI, you will shout "MBTI!". The direction of the word does not matter, i.e. it could be the bottom right to top left, left to right, and so on. Also, even though the type is previously found, "MBTI!" should be shouted again if the word is in a different location or direction.

		
Figure 1.	Figure 2.	Figure 3.
Let's find all the MBTI types on the board and shout "MBTI!" together.

입력
Your program is to read from standard input. The input starts with an integer N, M ( 1 \leq N,M \leq 200 ) representing rows and columns of boards. Following this are N lines containing M uppercase characters how does the alphabet board consist with.

출력
Your program is to write to standard output. Print exactly one line. The line should contain total occurrences of 16 MBTI types, which will be equal to the number of times you shouted 'MBTI!'

예제 입력 1 
5 5
JICDE
TFSFN
SESTF
EWERP
ABCDE
예제 출력 1 
3
You can find 1 ENFP, 1 ESTJ, 1 ISTP total 3 times

예제 입력 2 
5 4
ENFP
ENFP
ENFP
ENFP
ENFP
예제 출력 2 
9
노트
At figure 1, You can find MBTI 'ENFP' with consecutive diagonal blocks (0,3) to (3,0) 

At figure 2, you can find MBTI 'INFP' with consecutive diagonal blocks (3,3) to (0,0) and 'ISTJ' with consecutive horizontal blocks (3,3) to (3,0) 

At figure 3, you can find MBTI 'ISFJ' with consecutive diagonal blocks (0,0) to (3,3) and 'ISFJ' with consecutive horizontal blocks (1,0) to (1,3), 'ESTJ' with consecutive vertical blocks (0,1) to (3,1) 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    unordered_set<string> mbtiTypes = {
        "INFP", "INFJ", "INTP", "INTJ", 
        "ISFP", "ISFJ", "ISTP", "ISTJ", 
        "ENFP", "ENFJ", "ENTP", "ENTJ", 
        "ESFP", "ESFJ", "ESTP", "ESTJ"
    };
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 8; dir++) {
                string mbti = "";
                
                for (int step = 0; step < 4; step++) {
                    int ni = i + dx[dir] * step;
                    int nj = j + dy[dir] * step;
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        mbti += board[ni][nj];
                    } else {
                        mbti = "";
                        break;
                    }
                }
                
                if (mbti.length() == 4 && mbtiTypes.find(mbti) != mbtiTypes.end()) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}