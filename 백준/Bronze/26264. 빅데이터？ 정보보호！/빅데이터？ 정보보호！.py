"""
빅데이터? 정보보호!
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	1532	999	866	65.457%
문제
서울사이버대학교 빅데이터·정보보호학과는 빅데이터에 관심이 있는 학생들과 정보보호에 관심이 있는 학생들이 골고루 섞여 있는 학과이다.

빅데이터·정보보호학과에서 수업을 하던 노교수는 학생들이 빅데이터와 정보보호 중 어느 분야에 더 관심이 많은지 궁금해졌다. 그래서 학생들을 만날 때마다 항상 이를 물어보고 답을 bigdata 혹은 security로 구분하여 메모장에 적어두었는데, 실수로 띄어쓰기와 개행이 전혀 없는 상태로 기록해두었다.

이대로는 학생들이 빅데이터와 정보보호 중 어느 분야에 더 관심이 많은지를 알아낼 수 없기 때문에, 당신에게 분석을 의뢰했다. 물어본 학생의 수와 답이 주어질 때, 결과를 출력하자.

입력
첫 번째 줄에 물어본 학생의 수 
$N$이 주어진다. (
$1 \le N \le 100\,000$)

두 번째 줄에 메모장에 적힌 답들이 한 줄의 문자열로 주어진다. 문자열은 bigdata 또는 security로만 구성되어 있으며, 띄어쓰기 등의 다른 문자가 포함되어 있지 않다.

출력
첫 번째 줄에 정보보호 분야보다 빅데이터 분야에 관심이 있는 학생이 더 많으면 "bigdata?"를, 빅데이터 분야보다 정보보호 분야에 관심이 있는 학생이 더 많으면 "security!"를, 같으면 "bigdata? security!"를 따옴표 없이 출력한다.

예제 입력 1 
5
securitybigdatasecuritybigdatasecurity
예제 출력 1 
security!
예제 입력 2 
1
bigdata
예제 출력 2 
bigdata?
예제 입력 3 
6
bigdatabigdatabigdatasecuritysecuritysecurity
예제 출력 3 
bigdata? security!
"""

# Answer
import sys
input = sys.stdin.readline

N = int(input())
answers = input().rstrip()
bigdata = answers.count('bigdata')
security = answers.count('security')

if bigdata > security:
    print('bigdata?')
elif bigdata < security:
    print('security!')
else:
    print('bigdata? security!')