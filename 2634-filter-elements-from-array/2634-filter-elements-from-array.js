/*
2634. 배열에서 요소 필터링

정수 배열 arr과 필터링 함수 fn이 주어지면 필터링된 배열 filteredArr을 반환합니다.

fn 함수는 하나 또는 두 개의 인수를 받습니다:
- arr[i] - 배열의 숫자
- i - 배열[i]의 인덱스

filteredArr은 표현식 fn(arr[i], i)이 참 값으로 평가하는 배열의 요소만 포함해야 합니다. 
진실한 값은 Boolean(value)이 참을 반환하는 값입니다.

내장된 Array.filter 메서드 없이 해결하세요.

예제 1:
입력: arr = [0,10,20,30], fn = function greaterThan10(n) { return n > 10; }
Output: [20,30]
설명:
const newArray = filter(arr, fn); // [20, 30]
이 함수는 10보다 크지 않은 값을 필터링합니다.

예제 2:
입력: arr = [1,2,3], fn = function firstIndex(n, i) { return i === 0; }
Output: [1]
설명:
fn은 각 요소의 인덱스를 받을 수도 있습니다.
이 경우 함수는 인덱스 0이 아닌 요소를 제거합니다.

예제 3:
입력: arr = [-2,-1,0,1,2], fn = 함수 plusOne(n) { return n + 1 }
Output: [-2,0,1,2]
설명:
0과 같은 잘못된 값을 필터링해야 합니다.
 

제약 조건:

0 <= arr.length <= 1000
-10^9 <= arr[i] <= 10^9

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filterArr = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) filterArr.push(arr[i]);
    }
    return filterArr;
};