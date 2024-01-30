/*
150. 역 폴란드어 표기법 평가

역 폴란드어 표기법으로 산술식을 나타내는 문자열 토큰의 배열이 주어집니다.
식을 평가합니다. 표현식의 값을 나타내는 정수를 반환합니다.

참고하세요:

    유효한 연산자는 '+', '-', '*' 및 '/'입니다.
    각 피연산자는 정수 또는 다른 표현식일 수 있습니다.
    두 정수 사이의 나눗셈은 항상 0을 향해 잘립니다.
    0으로 나눈 값은 존재하지 않습니다.
    입력은 역연산 표기법으로 유효한 산술 표현식을 나타냅니다.
    답과 모든 중간 계산은 32비트 정수로 표현할 수 있습니다.



예제 1:
입력: tokens = ["2","1","+","3","*"]
Output: 9
설명: ((2 + 1) * 3) = 9

예제 2:

입력: tokens = ["4","13","5","/","+"]
Output: 6
설명: (4 + (13 / 5)) = 6

예제 3:

입력: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
출력: 22
설명: ((10 * (6 / ((9 + 3) * -11)))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution {
	public int evalRPN(String[] tokens) {
		Deque<Integer> stack = new ArrayDeque<>();
		for (String s : tokens) {
			int a, b;
			switch (s) {
				case "+" -> stack.push(stack.pop() + stack.pop());
				case "/" -> {
					b = stack.pop();
					a = stack.pop();
					stack.push(a / b);
				}
				case "*" -> stack.push(stack.pop() * stack.pop());
				case "-" -> {
					b = stack.pop();
					a = stack.pop();
					stack.push(a - b);
				}
				default -> stack.push(Integer.parseInt(s));
			}
		}
		return stack.pop();
	}
}