/*
2723. 두 가지 약속 추가

두 개의 약속 약속1과 약속2가 주어졌을 때, 새로운 약속을 반환합니다. 약속1과 약속2는 모두 숫자로 해결됩니다. 반환된 프라미스는 두 숫자의 합으로 해결되어야 합니다.
 

예시 1:
입력: 
약속1 = 새 약속(resolve => setTimeout(() => resolve(2), 20)), 
promise2 = new Promise(resolve => setTimeout(() => resolve(5), 60))
Output: 7
설명: 입력된 두 개의 프라미스는 각각 2와 5의 값으로 해결됩니다. 반환된 프라미스는 2 + 5 = 7의 값으로 해결되어야 합니다. 반환된 프라미스가 해결되는 시간은 이 문제에 대해 판단되지 않습니다.

예제 2:
Input: 
promise1 = new Promise(resolve => setTimeout(() => resolve(10), 50)), 
promise2 = new Promise(resolve => setTimeout(() => resolve(-12), 30))
Output: -2
설명: 두 입력 프로미스는 각각 10과 -12의 값으로 해결됩니다. 반환된 프라미스는 10 + -12 = -2의 값으로 해결되어야 합니다.
 

제약 조건:

약속1과 약속2는 숫자로 해결되는 프라미스입니다.

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    const [v1, v2] = await Promise.all([promise1,  promise2]);
    return v1 + v2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */