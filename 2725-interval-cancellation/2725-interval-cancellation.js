/*
2725. 인터벌 취소

함수 fn, 인자 배열 args, 간격 시간 t가 주어지면 취소 함수 cancelFn을 반환합니다.
취소TimeMs의 지연 후 반환된 취소 함수 취소Fn이 호출됩니다.

setTimeout(cancelFn, cancelTimeMs)
함수 fn은 인수와 함께 즉시 호출된 다음 
취소Fn이 취소TimeMs ms에서 호출될 때까지 t 밀리초마다 다시 호출되어야 합니다.

예제 1:
입력: fn = (x) => x * 2, args = [4], t = 35
Output: 
[
   {"time": 0, "반환": 8},
   {"time": 35, "returned": 8},
   {"time": 70, "반환": 8},
   {"time": 105, "반환": 8},
   {"time": 140, "반환": 8},
   {"time": 175, "반환": 8}
]
설명: 
const cancelTimeMs = 190;
const cancelFn = 취소 가능((x) => x * 2, [4], 35);
setTimeout(cancelFn, cancelTimeMs);

35ms마다 fn(4)가 호출됩니다. t=190ms가 되면 취소됩니다.
첫 번째 fn 호출은 0ms입니다. fn(4)는 8을 반환합니다.
두 번째 fn 호출은 35ms에 fn(4)는 8을 반환합니다.
세 번째 fn 호출은 70ms에 있습니다. fn(4)는 8을 반환합니다.
4번째 fn 콜은 105ms에 있습니다. fn(4)는 8을 반환합니다.
5번째 fn 통화는 140ms에 있습니다. fn(4)는 8을 반환합니다.
6번째 fn 콜은 175ms에 fn(4) 수익률 8.
190ms에 취소됨

예제 2:
입력: fn = (x1, x2) => (x1 * x2), args = [2, 5], t = 30
Output: 
[
   {"time": 0, "returned": 10},
   {"time": 30, "returned": 10},
   {"time": 60, "반환": 10},
   {"time": 90, "반환": 10},
   {"time": 120, "반환": 10},
   {"time": 150, "반환": 10}
]
설명: 
const cancelTimeMs = 165; 
const cancelFn = 취소 가능((x1, x2) => (x1 * x2), [2, 5], 30) 
setTimeout(cancelFn, cancelTimeMs)

30ms마다 fn(2, 5)가 호출됩니다. t=165ms가 되면 취소됩니다.
첫 번째 fn 호출은 0ms에 
두 번째 fn 호출은 30ms에 
세 번째 fn 호출은 60ms 
4번째 fn 통화는 90ms 
5번째 fn 통화는 120ms 
6번째 fn 통화는 150ms
165ms에 취소됨

예제 3:
입력: fn = (x1, x2, x3) => (x1 + x2 + x3), args = [5, 1, 3], t = 50
출력: 
[
   {"time": 0, "returned": 9},
   {"time": 50, "returned": 9},
   {"time": 100, "반환": 9},
   {"time": 150, "반환": 9}
]
설명: 
const cancelTimeMs = 180;
const cancelFn = 취소 가능((x1, x2, x3) => (x1 + x2 + x3), [5, 1, 3], 50)
setTimeout(cancelFn, cancelTimeMs)

50ms마다 fn(5, 1, 3)이 호출됩니다. t=180ms가 되면 취소됩니다. 
첫 번째 fn 호출은 0ms에
두 번째 fn 호출은 50ms에
세 번째 fn 호출은 100ms
4번째 fn 호출은 150ms
180ms에 취소됨
 

제약 조건:
fn은 함수입니다.
args는 유효한 JSON 배열
1 <= args.length <= 10
30 <= t <= 100
10 <= cancelTimeMs <= 500
*/

/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    fn(...args);
    let timer = setInterval(() => fn(...args), t);

    let cancelFn = () => clearInterval(timer);
    return cancelFn;
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 2;
 *  const args = [4], t = 35, cancelTimeMs = 190;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *
 *  setTimeout(cancel, cancelTimeMs);
 *   
 *  setTimeout(() => {
 *      console.log(result); // [
 *                           //     {"time":0,"returned":8},
 *                           //     {"time":35,"returned":8},
 *                           //     {"time":70,"returned":8},
 *                           //     {"time":105,"returned":8},
 *                           //     {"time":140,"returned":8},
 *                           //     {"time":175,"returned":8}
 *                           // ]
 *  }, cancelTimeMs + t + 15)    
 */