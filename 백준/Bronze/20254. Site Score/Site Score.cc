#include <iostream>
using namespace std;

int main() {
    int UR, TR, UO, TO;
    cin >> UR >> TR >> UO >> TO;

    int siteScore = 56 * UR + 24 * TR + 14 * UO + 6 * TO;
    cout << siteScore << endl;

    return 0;
}