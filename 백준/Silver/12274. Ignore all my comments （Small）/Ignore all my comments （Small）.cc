/*
Ignore all my comments (Small)
 
시간 제한	메모리 제한
5 초	512 MB
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "Case #1:" << endl;
    
    string code = "", line;
    while (getline(cin, line)) {
        code += line + '\n';
    }
    
    string result = "";
    stack<int> comment_positions; 
    
    for (int i = 0; i < code.size(); i++) {
        if (i + 1 < code.size() && code[i] == '/' && code[i+1] == '*') {
            comment_positions.push(i); 
            i++; 
        }
        else if (i + 1 < code.size() && code[i] == '*' && code[i+1] == '/') {
            if (!comment_positions.empty()) {
                comment_positions.pop();
                i++; 
            } else {
                result += code[i];
            }
        }
        else if (comment_positions.empty()) {
            result += code[i];
        }
    }
    
    cout << result;
    
    return 0;
}