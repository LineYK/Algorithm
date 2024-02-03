/*
2666. 하나의 함수 호출 허용

함수 fn이 주어졌을 때, 
fn이 최대 한 번만 호출되도록 한다는 점을 제외하면 원래 함수와 동일한 새 함수를 반환합니다.

반환된 함수가 처음 호출될 때는 fn과 동일한 결과를 반환해야 합니다.
이후 호출될 때마다 정의되지 않은 결과를 반환해야 합니다.
 
예제 1:
입력: fn = (a,b,c) => (a + b + c), calls = [[1,2,3],[2,3,6]]
출력: [{"calls":1,"value":6}]
설명:
const onceFn = once(fn);
onceFn(1, 2, 3); // 6
onceFn(2, 3, 6); // 정의되지 않음, fn이 호출되지 않음

예제 2:
입력: fn = (a,b,c) => (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
Output: [{"calls":1,"value":140}]
설명:
const onceFn = once(fn);
onceFn(5, 7, 4); // 140
onceFn(2, 3, 6); // 정의되지 않음, fn이 호출되지 않았습니다.
onceFn(4, 6, 8); // 정의되지 않음, fn이 호출되지 않음
 

제약 조건:
calls는 유효한 JSON 배열입니다.
1 <= calls.length <= 10
1 <= calls[i].length <= 100
2 <= JSON.stringify(calls).length <= 1000


/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let check = false;
    return function(...args){
        if (!check) {
            check = true;
            return fn(...args);
        }
        return;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
