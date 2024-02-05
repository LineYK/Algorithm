/*
2621. 수면

양의 정수 밀리초가 주어졌을 때, 밀리초 동안 절전 모드로 전환하는 비동기 함수를 작성합니다. 이 함수는 어떤 값도 해결할 수 있습니다.

예제 1:
입력: 밀리 = 100
Output: 100
설명: 100ms 후에 해결되는 프로미스를 반환해야 합니다.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});

예제 2:
입력: 밀리 = 200
Output: 200
설명: 200ms 후에 해결되는 프로미스를 반환해야 합니다.
 

제약 조건:
1 <= 밀리 <= 1000

/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(r => setTimeout(r, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */