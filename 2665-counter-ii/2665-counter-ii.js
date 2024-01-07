/*
2665. 카운터 II

createCounter 함수를 작성합니다. 
이 함수는 초기 정수 init을 받아들여야 합니다. 세 개의 함수가 있는 객체를 반환해야 합니다.

세 가지 함수는 다음과 같습니다:

increment()는 현재 값을 1씩 증가시킨 다음 반환합니다.
decrement()는 현재 값을 1만큼 감소시킨 다음 반환합니다.
reset()은 현재 값을 초기값으로 설정한 다음 반환합니다.
 

예제 1:
입력: init = 5, calls = ["increment","reset","decrement"]
Output: [6,5,4]
설명:
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4

예제 2:
입력: init = 0, calls = ["증가","증가","감소","재설정","재설정"]
Output: [1,2,1,0,0]
설명:
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0
 

제약 조건:
-1000 <= init <= 1000
0 <= calls.length <= 1000
calls[i]는 "증가", "감소", "재설정" 중 하나입니다.
*/

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count = init;
    return {
        increment: () => count += 1,
        decrement: () => count -= 1,
        reset: () => count = init
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */