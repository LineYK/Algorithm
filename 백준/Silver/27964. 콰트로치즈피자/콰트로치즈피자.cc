/*
콰트로치즈피자
 
시간 제한   메모리 제한
1 초   1024 MB

문제
치즈와 피자에 환장하는 비행씨는 매일같이 치즈피자를 사 먹다가 지갑이 거덜 나고 말았다. 
만들어 먹는 것이 사 먹는 것보다 싸다는 것을 안 비행씨는 여러 가지 토핑을 가져와서 
직접 피자를 만들어 먹기로 했다.

콰트로치즈피자는 이름 그대로, 서로 다른 네 종류의 치즈가 토핑으로 들어가야 한다. 
수많은 치즈피자를 먹어 온 비행씨는 토핑의 이름이 Cheese로 끝나면 이 토핑이 치즈라는 사실을 알고 있다. 
비행씨가 가져온 토핑의 목록을 보고, 이 토핑의 일부 혹은 전부를 이용하여 
콰트로치즈피자를 만들 수 있는지 답해 보자.

입력
첫 번째 줄에 토핑의 개수가 
$1$ 이상 
$100$ 이하의 정수로 주어진다.

두 번째 줄에는 한 줄로 구성된 토핑의 목록이 주어진다. 각 토핑들은 공백으로 구분되어 있으며, 
$1$개 이상 
$100$개 이하의 영문 대소문자로 구성되어 있다. 대소문자를 구분함에 유의하라.

출력
입력으로 주어진 토핑의 목록으로 콰트로치즈피자를 만들 수 있으면 yummy, 만들 수 없으면 sad를 출력하라.

예제 입력 1 
4
CheddarCheese MozzarellaCheese GoudaCheese GranaPadanoCheese
예제 출력 1 
yummy
4개의 치즈로 맛있는 콰트로치즈피자를 만들었다.

예제 입력 2 
4
MozzarellaCheese MozzarellaCheese MozzarellaCheese MozzarellaCheese
예제 출력 2 
sad
모짜렐라 치즈만으로는 콰트로치즈피자를 만들 수 없어 비행씨가 실의에 빠지고 말았다.

예제 입력 3 
4
CheeseBurger CheeseBall CheeseCake CheeseRavioli
예제 출력 3 
sad
이 토핑들 중에는 치즈가 없어서, 콰트로치즈피자를 만들 수가 없다.

예제 입력 4 
7
C Chess cheese Cheesa Cheesz Cheesp Cheese
예제 출력 4 
sad
이 토핑들 중 치즈인 것은 마지막 토핑밖에 없다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;

    set<string> cheeseSet;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if(s.find("Cheese",s.size()-6)!=string::npos)
           cheeseSet.insert(s);
    }
    
    if (cheeseSet.size() >= 4) {
        cout << "yummy";
    } else {
        cout << "sad";
    }
       
    return 0;
}