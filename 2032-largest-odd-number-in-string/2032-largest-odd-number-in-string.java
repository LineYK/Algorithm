/*
1903. 문자열에서 가장 큰 홀수
Easy

큰 정수를 나타내는 문자열 num이 주어집니다. num의 비어 있지 않은 부분 문자열인 가장 큰 값의 홀수 정수를 문자열로 반환하거나, 홀수 정수가 존재하지 않으면 빈 문자열 ""을 반환합니다.

부분 문자열은 문자열 내의 연속된 문자 시퀀스입니다.

 
예제 1:
입력: num = "52"
Output: "5"
설명: 비어 있지 않은 유일한 하위 문자열은 "5", "2" 및 "52"입니다. "5"는 유일한 홀수입니다.

예 2:
입력: num = "4206"
Output: ""
설명: "4206"에는 홀수가 없습니다.

예제 3:
입력: num = "35427"
Output: "35427"
설명: "35427"은 이미 홀수입니다.
 

제약 조건:

1 <= num.length <= 105
num은 숫자로만 구성되며 선행 0을 포함하지 않습니다.
*/

class Solution {
    public String largestOddNumber(String num) {
        if((int)num.charAt(num.length()-1)%2==1) return num;
        int i=num.length()-1;
        while(i>=0){
            int n=num.charAt(i);
            if(n%2==1) return num.substring(0,i+1);
            i--;
        }
        return "";
    }
}