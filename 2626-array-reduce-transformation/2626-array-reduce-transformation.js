/*
2626. 어레이 Reduce 변환 

정수 배열 nums, 감속 함수 fn, 초기값 init이 주어졌을 때, 
배열의 각 요소에 대해 이전 요소에 대한 계산의 반환값을 전달하면서 
순차적으로 fn 함수를 실행하여 얻은 최종 결과를 반환합니다.

이 결과는 배열의 모든 요소가 처리될 때까지 
val = fn(init, nums[0]), val = fn(val, nums[1]), val = fn(val, nums[2]), ...와 같은 
연산을 통해 얻을 수 있습니다. 
그러면 val의 최종 값이 반환됩니다.

배열의 길이가 0이면 함수는 init을 반환해야 합니다.

내장된 Array.reduce 메서드를 사용하지 않고 해결하세요.

예제 1:
Input:
nums = [1,2,3,4]
fn = 함수 합계(accum, curr) { 반환 accum + curr; }
init = 0
Output: 10
설명:
처음에 값은 init=0입니다.
(0) + nums[0] = 1
(1) + nums[1] = 3
(3) + nums[2] = 6
(6) + nums[3] = 10
최종 답은 10입니다.

예제 2:
입력:
nums = [1,2,3,4]
fn = 함수 합계(accum, curr) { 반환 accum + curr * curr; }
init = 100
Output: 130
설명:
처음에 값은 init=100입니다.
(100) + nums[0] * nums[0] = 101
(101) + nums[1] * nums[1] = 105
(105) + nums[2] * nums[2] = 114
(114) + nums[3] * nums[3] = 130
최종 답은 130입니다.

예 3:
입력:
nums = []
fn = 함수 합계(accum, curr) { 반환 0; }
init = 25
Output: 25
설명: 빈 배열의 경우 대답은 항상 init입니다.
 

제약 조건:

0 <= nums.length <= 1000
0 <= nums[i] <= 1000
0 <= init <= 1000

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let val = init;
    nums.forEach(n => val = fn(val, n));
    return val;
};