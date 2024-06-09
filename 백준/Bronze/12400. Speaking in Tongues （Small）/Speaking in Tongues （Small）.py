"""
Speaking in Tongues (Small)
 
시간 제한	메모리 제한
5 초	512 MB
문제

Google에서는 Googlerese라는 최상의 언어를 개발했습니다. 
텍스트를 Googlerese로 번역하기 위해 Google은 
모든 메시지를 가져와 각 영어 문자를 다른 영어 문자로 대체합니다. 
이 매핑은 일대일 방식으로 이루어지므로 동일한 입력 문자는 항상 동일한 출력 문자로 대체되고, 
다른 입력 문자는 항상 다른 출력 문자로 대체됩니다. 문자는 그 자체로 대체될 수 있습니다. 
공백은 그대로 유지됩니다.

예를 들어(여기에 힌트가 있습니다!), 
저희의 멋진 번역 알고리즘에는 'a'->'y', 'o'->'e', 'z'->'q'의 세 가지 매핑이 포함되어 있습니다. 
즉, 'a zoo'는 'y qee'가 됩니다.

구글리즈는 가능한 최상의 대체 매핑을 기반으로 하며, 절대 변경하지 않습니다. 
항상 동일하게 유지됩니다. 모든 테스트 사례에서요. 
매핑의 나머지 부분은 문제를 너무 쉽게 만들 수 있으므로 알려드리지 않겠지만, 
아래에 도움이 될 만한 몇 가지 예가 있습니다.

구글러로 된 텍스트가 주어지면 이를 다시 일반 텍스트로 번역할 수 있나요?

이 문제 해결하기
일반적으로 Google 코드 잼 문제에는 작은 입력 1개와 큰 입력 1개가 있습니다. 
이 문제에는 작은 입력이 1개만 있습니다. 작은 입력을 풀면 이 문제 풀이를 완료한 것입니다.

입력
입력의 첫 번째 줄은 테스트 케이스 수, T. 
테스트 케이스는 한 줄에 하나씩 이어집니다.

각 줄은 'a' - 'z' 문자를 포함하는 하나 이상의 단어로 구성된 Googlerese의 문자열 G로 구성됩니다. 
연속된 단어 사이에는 정확히 하나의 공백(' ') 문자가 있어야 하며, 
어떤 줄의 시작이나 끝에도 공백이 없어야 합니다.

제한
1 ≤ T ≤ 30.
G는 최대 100자까지만 포함됩니다.
어떤 텍스트도 유효한 영어임을 보장할 수 없습니다.

출력
For each test case, output one line containing 
"Case #X: S" where X is the case number and S is the string that becomes G in Googlerese.

예제 입력 1 
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
예제 출력 1 
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
"""

# Answer
import sys
input = sys.stdin.readline

input_str = [
    "aoz",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv",
]
google_str = [
    "yeq",
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up",
]

dict = {}

for i in range(4):
    for j in range(len(input_str[i])):
        dict[input_str[i][j]] = google_str[i][j]
dict["q"] = "z"

T = int(input())
for i in range(T):
    G = input().strip()
    S = ""
    for g in G:
        if g == " ":
            S += " "
        else:
            S += dict[g]
    print(f"Case #{i+1}: {S}")