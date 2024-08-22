/*
메시지 디코딩 
 
시간 제한 메모리 제한
1 초 1024 MB
문제
소들은 방금 메시지 암호화에 대해 배웠기 때문에 흥분하고 있습니다. 
비밀 메시지를 이용해 다른 농장의 소들과 모임을 계획할 수 있을 거라고 생각하기 때문입니다.

소는 지능이 높다고 알려져 있지 않습니다. 
그들의 암호화 방식은 DES나 BlowFish 또는 그 어떤 훌륭한 비밀 코딩 방법과는 전혀 다릅니다. 
아니, 단순한 치환 암호를 사용합니다.

소들은 암호 해독 키와 비밀 메시지를 가지고 있습니다. 암호를 해독하도록 도와주세요. 
키는 다음과 같습니다:

        yrwhsoujgcxqbativndfezmlpk

즉, 비밀 메시지의 'a'는 실제로는 'y'를 의미하고, 
비밀 메시지의 'b'는 실제로는 'r'을 의미하며, 
'c'는 'w'로 해독되는 식입니다. 
공백은 암호화되지 않고 그대로 유지됩니다.

입력 텍스트는 대문자 또는 소문자이며, 둘 다 동일한 복호화 키를 사용하여 복호화되며, 
물론 적절한 대소문자를 유지합니다.

입력
1줄: 복호화 키를 나타내는 소문자 26자
2번째 줄: 2줄: 복호화할 메시지를 최대 80자까지 입력합니다.

출력
1줄: 복호화된 메시지인 한 줄입니다. 
두 번째 입력 줄과 길이가 같아야 합니다.

예제 입력 1 
eydbkmiqugjxlvtzpnwohracsf
Kifq oua zarxa suar bti yaagrj fa xtfgrj

예제 출력 1 
Jump the fence when you seeing me coming
*/

#include <iostream>

using namespace std;

int main() {
    string key;
    string message;

    cin >> key;
    cin.ignore();
    getline(cin, message);

    for (int i = 0; i < message.size(); i++) {
        if (message[i] == ' ') {
            cout << ' ';
        } else {
            if (message[i] >= 'a' && message[i] <= 'z') {
                cout << key[message[i] - 'a'];
            } else {
                cout << (char)(key[message[i] - 'A'] - 'a' + 'A');
            }
        }
    }


    return 0;
}