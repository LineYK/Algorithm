/*
7 더하기
 
시간 제한	메모리 제한
1 초	128 MB

문제
7 세그먼트 디스플레이는 오른쪽 그림과 같이 일곱개의 LED로 이루어져 있다. 
각각의 LED는 켜있거나 꺼져있을 수 있고, 독립적으로 작동한다. 
이러한 LED의 조합은 총 127가지가 있으며, 주로 숫자 0부터 9까지를 표현하는데 사용된다. 

프로그래머는 이 디스플레이에 7비트 숫자를 전송해서 조정할 수 있다. 예를 들어, 1을 표시하려면 1번과 3번 LED만 켜야한다. 따라서, 0001010을 전송하면 된다. 이 7비트 숫자를 코드라고 하며, 보통 10진수로 표현한다. 

LED의 조합은 총 127가지가 있기 때문에, 코드는 3자리 숫자로 나타낼 수 있다. 예를 들어, 1은 0001010을 전송하면 되고 이 수의 10진수 값은 10이기 때문에, 코드로는 010으로 나타낸다.

한 자리 이상의 수를 나타낼 때는 코드를 이어서 사용하면 된다. 예를 들어, 13은 010079로 나타내면 되고, 144는 010106106으로 나타내면 된다.

7 세그먼트 디스플레이 상에서 코드로 나타낸 두 수가 주어졌을 때, 두 수의 합을 7 세그먼트 디스플레이에서 코드로 출력하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 A+B=꼴이며, A와 B는 두 수 a와 b를 7 세그먼트 디스플레이 상에서의 코드로 표현한 값이다. (0 < a,b < a+b < 1,000,000,000) 마지막 줄에는 BYE가 주어진다.

출력
각 테스트 케이스에 대해서, 한 줄에 하나씩 A+B=C를 출력한다. A와 B는 입력에서 주어진 값이며, C는 a+b를 다시 7 세그먼트 디스플레이 코드로 나타낸 값이다.

예제 입력 1 
010079010+010079=
106010+010=
BYE
예제 출력 1 
010079010+010079=010106106
106010+010=106093
*/
#include <bits/stdc++.h>
using namespace std;

// 주어진 7세그먼트 코드 값
const int seg[10] = {
    0b0111111, // 0 -> 63
    0b0001010, // 1 -> 10
    0b1011101, // 2 -> 93
    0b1001111, // 3 -> 79
    0b1101010, // 4 -> 106
    0b1100111, // 5 -> 103 
    0b1110111, // 6 -> 119 
    0b0001011, // 7 -> 11
    0b1111111, // 8 -> 127
    0b1101011  // 9 -> 107
};

map<int, int> decode_map;
vector<string> encode_map(10);

long long decode(const string& code) {
    long long number = 0;
    for (size_t i = 0; i < code.length(); i += 3) {
        int val = stoi(code.substr(i, 3));
        number = number * 10 + decode_map[val];
    }
    return number;
}

string encode(long long number) {
    string s_num = to_string(number);
    string result_code = "";
    for (char c : s_num) {
        result_code += encode_map[c - '0'];
    }
    return result_code;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; ++i) {
        decode_map[seg[i]] = i;
        stringstream ss;
        ss << setfill('0') << setw(3) << seg[i];
        encode_map[i] = ss.str();
    }

    string line;
    while (cin >> line && line != "BYE") {
        
        size_t plus_pos = line.find('+');
        size_t equal_pos = line.find('='); 

        string codeA = line.substr(0, plus_pos);
        string codeB = line.substr(plus_pos + 1, equal_pos - (plus_pos + 1));

        long long numA = decode(codeA);
        long long numB = decode(codeB);
        long long sum = numA + numB;
        string codeC = encode(sum);

        cout << line << codeC << endl;
    }

    return 0;
}