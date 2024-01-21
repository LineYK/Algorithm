/*
2629. 기능 구성

함수 배열 [f1, f2, f3, ..., fn]이 주어졌을 때, 
함수 배열의 함수 구성인 새로운 함수 fn을 반환합니다.

[f(x), g(x), h(x)]의 함수 구성은 fn(x) = f(g(h(x)))입니다.

빈 함수 목록의 함수 구성은 동일 함수 f(x) = x입니다.

배열의 각 함수는 하나의 정수를 입력으로 받아들이고 
하나의 정수를 출력으로 반환한다고 가정할 수 있습니다.

 
예제 1:
입력: 함수 = [x => x + 1, x => x * x, x => 2 * x], x = 4
Output: 65
설명:
오른쪽에서 왼쪽으로 평가 ...
x = 4로 시작합니다.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65
예제 2:

입력: 함수 = [x => 10 * x, x => 10 * x, x => 10 * x], x = 1
출력 1000
설명:
오른쪽에서 왼쪽으로 평가 ...
10 * (1) = 10
10 * (10) = 100
10 * (100) = 1000
예제 3:

입력: functions = [], x = 42
Output: 42
설명: 설명:
0 함수의 구성은 동일성 함수입니다.
 

제약 조건입니다:
-1000 <= x <= 1000
0 <= functions.length <= 1000
모든 함수는 단일 정수를 받아 반환합니다.

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        return functions.reduceRight((acc, f) => f(acc), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */