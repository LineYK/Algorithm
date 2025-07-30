#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string key;
    getline(cin, key);
    key.erase(remove_if(key.begin(), key.end(),
        [](char c){ return !(c >= 'A' && c <= 'Z'); }),
        key.end());

    string line;
    getline(cin, line);
    string msg;
    for(char c : line){
        if(c >= 'A' && c <= 'Z')
            msg.push_back(c);
    }

    int K = key.size();
    string enc;
    enc.reserve(msg.size());
    for(int i = 0; i < (int)msg.size(); i++){
        int shift = key[i % K] - 'A';
        char plain = msg[i];
        char cipher = char((plain - 'A' + shift) % 26 + 'A');
        enc.push_back(cipher);
    }

    cout << enc << "\n";
    return 0;
}