/*
베스트셀러 
 
시간 제한 메모리 제한	
1초 1024MB	

문제
스토어를 운영하면서 가장 많은 수익을 내는 곳과 가장 많이 판매되는 품목을 알고 싶습니다. 
품목 목록, 각 품목의 판매 횟수 및 각 판매당 수익이 있습니다. 각 품목 이름은 단일 단어입니다. 
한 품목의 총 수익은 판매 횟수에 해당 품목의 수익을 곱한 값입니다. 
이 데이터를 받아 다음 규칙을 사용하여 정렬된 목록을 생성하는 프로그램을 작성합니다:

정렬 규칙:
총 수익에 따라 내림차순으로 항목 정렬
총 수익이 동일한 품목의 경우 판매 수에 따라 내림차순으로 정렬합니다.
총 수익과 판매 수가 동일한 품목의 경우 이름별로 오름차순으로 정렬합니다.

입력
itemName numberOf판매수 profitEach판매수 삼중항으로 구성된 입력 수는 알 수 없으며, 
각 삼중항은 자체 줄에 있고 한 줄의 각 값은 한 칸으로 구분됩니다.
itemName은 단일 단어이며 각 입력 줄의 형식은 다음과 같습니다:
itemName numberOfSales profitEachSale

출력
정렬된 목록을 표시하며 각 항목은 자체 줄에 표시됩니다. 항목 표시 형식은 다음과 같습니다:
$totalProfit - itemName/numberOfSales
대시 앞뒤에 공백이 하나씩 있어야 하며 수익 값은 소수점 이하 자릿수가 정확히 두 자리여야 합니다.

예제 입력 1 
pens 120 .12
binders 120 1.15
hats 24 6.00
shoes 12 12.00
rings 44 22.86
coats 14 28.64
boots 12 12.00
예제 출력 1 
$1005.84 - rings/44
$400.96 - coats/14
$144.00 - hats/24
$144.00 - boots/12
$144.00 - shoes/12
$138.00 - binders/120
$14.40 - pens/120
*/

#include <bits/stdc++.h>
using namespace std;

class Item{
public:
    string name;
    int numberOfSales;
    double profitEachSale;
    double totalProfit;
    Item(string name, int numberOfSales, double profitEachSale){
        this->name = name;
        this->numberOfSales = numberOfSales;
        this->profitEachSale = profitEachSale;
        this->totalProfit = numberOfSales * profitEachSale;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string itemName;
    int numberOfSales;
    double profitEachSale;

    vector<Item> items;

    while (cin >> itemName >> numberOfSales >> profitEachSale) {
        items.push_back(Item(itemName, numberOfSales, profitEachSale));
    }
    
    sort(items.begin(), items.end(), [](Item a, Item b){
        if(a.totalProfit == b.totalProfit){
            if(a.numberOfSales == b.numberOfSales){
                return a.name < b.name;
            }
            return a.numberOfSales > b.numberOfSales;
        }
        return a.totalProfit > b.totalProfit;
    });

    cout << fixed;
    cout.precision(2);

    for(auto item : items){
        cout << "$" << item.totalProfit << " - " << item.name << "/" << item.numberOfSales << '\n';
    }

    return 0;
}
