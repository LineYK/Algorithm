/*

캐스팅 아웃 나인

 

시간 제한 메모리 제한

1초 128MB   

문제

위대한 수학자 레오나르도 다 피사 피보나치(1170-1240)에 대해 들어보셨을 것입니다. 피보나치는 1202년에 처음 출간된 그의 저서 '리베르 아바치'에서 덧셈, 뺄셈, 곱셈을 계산하는 많은 알고리즘 중 캐스팅 아웃 나인 절차를 설명했습니다. 역사가들에 따르면 이 절차는 아랍인에 의해 유럽으로 전해졌지만 인도 대륙 어딘가에서 개발되었을 것으로 추정되며, 따라서 “힌두교 수표”라고도 불립니다.

“9를 던지기"는 10x ≡ 1(mod 9)의 합동성을 사용하는 곱셈의 기본 수표입니다. x ≡ y (mod z)를 쓸 때 실제로는 (x mod z)가 (y mod z)와 같다고 말하는 것임을 기억하세요.

a, b를 곱이 c인 자연수라고 하고, 이 수들의 자릿수의 합을 a ̄, ̄b, a n d c ̄라고 합니다. a ≡ a ̄ ( m o d 9 ) , b ≡ ̄b ( m o d 9 ) , a n d c ≡ c ̄ ( m o d 9 ) 입니다 . ㅏ × b ≡ a ̄ × ̄b ( m o d 9 ) , 따라서 ㅏ ̄ × ̄b ≡ c ̄ (mod 9). 따라서 c와 a ̄ × ̄b가 일치하지 않는 경우(mod 9), 곱셈이 잘못 수행된 것입니다.

예를 들어 12345 × 67890 = 838102050. 12345와 67890의 자릿수의 합은 각각 15와 30이며 이 둘의 곱은 450입니다. 마찬가지로 838102050 의 자릿수 합은 27입니다. 그리고 450 ≡ 27 ≡ 0(mod 9)이므로 힌두 체크는 일치함을 나타냅니다.

다른 예로 13579×24680 = 334129720 를 잘못 계산했다고 가정해 보겠습니다. a ̄× ̄b = 25 × 20 = 500 ≡ 5(mod 9)이고, c ̄ = 31 ≡ 4(mod 9)이기 때문입니다. 따라서 곱셈은 확실히 틀린 계산입니다.

a + b ≡ a ̄ + ̄b (mod 9)이므로 힌두 검사는 덧셈을 확인하는 데에도 사용할 수 있습니다.

주어진 덧셈이나 곱셈이 힌두 체크를 통과하는지 여부를 결정하는 프로그램을 작성하세요.

입력

프로그램은 하나 이상의 테스트 케이스에서 테스트됩니다. 각 테스트 케이스는 별도의 입력 줄에 지정됩니다. 각 줄은 다음과 같은 형식입니다:

a+b=c.

또는,

a*b=c.

줄 끝에 '.'가 있는 것을 주목하세요. 'a', 'b', 'c'는 자연수입니다. 숫자와 기호('+', '*', '=' 및 '.',) 사이에는 공백이 없지만 '.' 뒤에 후행 공백이 나타날 수 있습니다.

테스트 케이스의 일부가 아닌 입력 파일의 마지막 줄에는 '.'가 하나만 있습니다.

출력

각 테스트 케이스에 대해 다음 형식을 사용하여 결과를 한 줄에 출력합니다:

k.␣result

여기서 k는 테스트 케이스 번호(1부터 시작)이며, 이 테스트 케이스의 덧셈 또는 곱셈 연산이 힌두교 검사를 통과하면 결과는 “PASS”입니다. 그렇지 않으면 결과는 “NOT!”입니다.

예제 입력 1 

12345*67890=838102050.

13579*24680=334129720.

23+11=34.

.

예제 출력 1 

1. PASS

2. NOT!

3. PASS

*/

#include <bits/stdc++.h>

using namespace std;

int digitSum(const string& num) {
    int sum = 0;
    for (char c : num) {
        sum += (c - '0');
    }

    // 9로 나눈 나머지를 반환, 단 9의 배수일 경우 9 반환
    return sum % 9 == 0 ? 9 : sum % 9;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;

    int testCase = 1;

    

    while (getline(cin, line) && line != ".") {
        char op;

        if (line.find('+') != string::npos) {
            op = '+';
        } else {
            op = '*';

        }
        
        // 문자열 파싱해서 a, b, c 추출
        size_t opPos = line.find(op);
        size_t eqPos = line.find('=');
        size_t dotPos = line.find('.');
        
        string a = line.substr(0, opPos);
        string b = line.substr(opPos + 1, eqPos - opPos - 1);
        string c = line.substr(eqPos + 1, dotPos - eqPos - 1);      
        
        int aSum = digitSum(a);
        int bSum = digitSum(b);
        int cSum = digitSum(c);
        bool isPass = false;

        if (op == '+') {
            int expectedSum = (aSum + bSum) % 9;
            if (expectedSum == 0) expectedSum = 9;
            isPass = (expectedSum == cSum);

        } else {

            int expectedProd = (aSum * bSum) % 9;
            if (expectedProd == 0) expectedProd = 9;
            isPass = (expectedProd == cSum);

        }
        cout << testCase << ". " << (isPass ? "PASS" : "NOT!") << "\n";
        testCase++;

    }
    return 0;

}