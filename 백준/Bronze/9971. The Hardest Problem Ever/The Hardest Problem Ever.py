"""
The Hardest Problem Ever 다국어
 
시간 제한	메모리 제한
1 초	128 MB
문제
줄리어스 시저는 위험과 음모의 시대에 살았습니다. 
시저가 직면한 가장 어려운 상황은 자신을 살아남게 하는 것이었습니다. 
그가 살아남기 위해, 그는 최초의 암호 중 하나를 만들기로 결심했습니다. 
이 암호는 어떻게 작동하는지 모르면 아무도 알아낼 수 없을 정도로 매우 견고했습니다. 
당신은 시저의 군대의 부하 지휘관입니다. 
당신의 임무는 시저가 보낸 메시지를 해독하여 당신의 장군에게 제공하는 것입니다. 
암호는 간단합니다. 
평문 메시지의 각 글자를 오른쪽으로 다섯 자리 이동하여 안전한 메시지를 만듭니다
(예: 문자가 ‘A’인 경우 암호문은 ‘F’가 됩니다). 
평문을 만들기 위해, 반대로 작업해야 합니다:

암호문
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

평문
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
이 암호에서 문자는 이동합니다. 
모든 비알파벳 문자는 그대로 두어야 하며, 모든 알파벳 문자는 대문자로 변환됩니다.

입력
이 문제에 대한 입력은 최대 100개의 데이터 세트로 구성된 (빈칸이 없는) 시리즈로 구성됩니다. 
각 데이터 세트는 다음 설명에 따라 포맷되며, 데이터 세트 사이에 빈 줄은 없습니다. 
모든 문자는 대문자입니다.

단일 데이터 세트는 3개의 구성 요소로 이루어져 있습니다:

시작 라인  단일 라인, “START”
암호 메시지  1에서 200자의 문자로 이루어진 단일 라인, 시저로부터의 단일 메시지를 포함합니다.
종료 라인  단일 라인, “END”
마지막 데이터 세트 이후에는 단일 라인, “ENDOFINPUT”이 옵니다.

출력
각 데이터 세트에 대해 정확히 한 줄의 출력이 있습니다. 
이것은 시저의 원래 메시지입니다.

예제 입력 1 
START
NS BFW, JAJSYX TK NRUTYFSHJ FWJ YMJ WJXZQT TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
예제 출력 1 
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
"""

# Answer
import sys
input = sys.stdin.readline 

ans = ''

while True:
    s = input().strip()
    if s == "ENDOFINPUT":
        break
    if s == "START":
        s = input().strip()
        for c in s:
            if c.isalpha():
                ans += chr((ord(c) - ord('A') - 5) % 26 + ord('A'))
            else:
                ans += c
    ans += '\n'
    
ans = ans.split('\n')

for a in ans:
    print(a if a != '' else '\n', end='')