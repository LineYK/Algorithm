/*
2623. 메모하기

함수 fn이 주어지면 해당 함수의 메모화된 버전을 반환합니다.

메모화된 함수는 동일한 입력으로 두 번 호출되지 않는 함수입니다. 대신 캐시된 값을 반환합니다.

가능한 입력 함수는 합계, 피브, 계승의 세 가지가 있다고 가정할 수 있습니다.

sum은 두 개의 정수 a와 b를 받아 a + b를 반환합니다.
fib는 단일 정수 n을 받아 n이 1 <= 1이면 1을, 그렇지 않으면 fib(n - 1) + fib(n - 2)를 반환합니다.
팩토리얼은 단일 정수 n을 받아들이고 n <= 1이면 1을, 그렇지 않으면 팩토리얼(n - 1) * n을 반환합니다.
 

예제 1:
Input:
fnName = "합계"
actions = ["call","call","getCallCount","call","getCallCount"]
values = [[2,2],[2,2],[],[1,2],[]]
Output: [4,4,1,3,2]
설명:
const sum = (a, b) => a + b;
const memoizedSum = memoize(sum);
memoizedSum(2, 2); // "call" - 4를 반환합니다. (2, 2)가 이전에 보이지 않았기 때문에 sum()이 호출되었습니다.
memoizedSum(2, 2); // "call" - 4를 반환합니다. 그러나 이전에 동일한 입력이 보였기 때문에 sum()이 호출되지 않았습니다.
// "getCallCount" - 총 통화 횟수: 1
memoizedSum(1, 2); // "call" - 반환값 3. 이전에 (1, 2)가 표시되지 않았기 때문에 sum()이 호출되었습니다.
// "getCallCount" - 총 통화 횟수: 2

예제 2:
입력:
fnName = "계승"
actions = ["call","call","call","getCallCount","call","getCallCount"]
values = [[2],[3],[2],[],[3],[]]
Output: [2,6,2,2,6,2]
설명입니다:
const 팩토리얼 = (n) => (n <= 1) ? 1 : (n * 계승(n - 1));
const memoFactorial = memoize(factorial);
memoFactorial(2); // "호출" - 2를 반환합니다.
memoFactorial(3); // "call" - 6을 반환합니다.
memoFactorial(2); // "call" - 반환 2. 그러나 이전에 2가 보였기 때문에 계승은 호출되지 않았습니다.
// "getCallCount" - 총 통화 횟수: 2
memoFactorial(3); // "call" - 6을 반환합니다. 그러나 이전에 3이 표시되었기 때문에 계승은 호출되지 않았습니다.
// "getCallCount" - 총 통화 횟수: 2

예제 3:
입력:
fnName = "fib"
actions = ["call","getCallCount"]
values = [[5],[]]
Output: [8,1]
설명:
fib(5) = 8 // "call"
// "getCallCount" - 총 통화 횟수: 1
 

제약 조건:

0 <= a, b <= 10^5
1 <= n <= 10
0 <= actions.length <= 10^5
actions.length === values.length
actions[i]는 "call" 및 "getCallCount" 중 하나입니다.
fnName은 "합계", "계승", "섬유" 중 하나입니다.
*/

/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = {};

    return function(...args) {
        const key = String(args);
        if (key in cache) return cache[key];

        const res = fn(...args);
        cache[key] = res;
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */