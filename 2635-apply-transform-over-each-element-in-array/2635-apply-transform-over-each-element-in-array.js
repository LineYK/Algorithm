/*
2635. 배열의 각 요소에 변형 적용

정수 배열 arr과 매핑 함수 fn이 주어졌을 때, 각 요소에 변환이 적용된 새 배열을 반환합니다.

반환된 배열은 반환된 배열[i] = fn(arr[i], i)이 되도록 만들어야 합니다.

내장된 Array.map 메서드 없이 해결하세요.

 
예제 1:
입력: arr = [1,2,3], fn = 함수 plusone(n) { return n + 1; }
Output: [2,3,4]
설명:
const newArray = map(arr, plusone); // [2,3,4]
이 함수는 배열의 각 값을 하나씩 증가시킵니다. 

예제 2:
입력: arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
Output: [1,3,5]
설명: 이 함수는 각 값을 해당 값이 있는 인덱스만큼 증가시킵니다.

예제 3:
입력: arr = [10,20,30], fn = function constant() { return 42; }
Output: [42,42,42]
설명: 이 함수는 항상 42를 반환합니다.
 

제약 조건:
0 <= arr.length <= 1000
-10^9 <= arr[i] <= 10^9
fn은 숫자를 반환합니다.

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for (let i = 0; i < arr.length; i++) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};