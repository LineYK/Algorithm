/*
2715. 시간 초과 취소

함수 fn, 인자 배열 args, 시간 초과 t(밀리초)가 주어지면 취소 함수 cancelFn을 반환합니다.

취소 시간 t만큼 지연된 후 반환된 취소 함수 취소Fn이 호출됩니다.

setTimeout(취소Fn, 취소TimeMs)
처음에는 함수 fn의 실행을 t 밀리초 지연시켜야 합니다.

t 밀리초가 지연되기 전에 취소Fn 함수가 호출되면 지연된 fn의 실행을 취소해야 합니다. 그렇지 않으면 지정된 지연 시간 t 이내에 취소Fn이 호출되지 않으면 제공된 인수를 인수로 사용하여 fn을 실행해야 합니다.


예제 1:
입력: fn = (x) => x * 5, args = [2], t = 20
Output: [{"time": 20, "returned": 10}]]
설명: 
const cancelTimeMs = 50;
const cancelFn = 취소 가능((x) => x * 5, [2], 20);
setTimeout(cancelFn, cancelTimeMs);

취소는 20ms에 fn(2)가 실행된 후 발생한 취소 시간(50ms)의 지연 후에 발생하도록 예약되었습니다.

예제 2:
입력: fn = (x) => x**2, args = [2], t = 100
Output: []
설명: 
const cancelTimeMs = 50;
const cancelFn = 취소 가능((x) => x**2, [2], 100);
setTimeout(cancelFn, cancelTimeMs);

취소는 100ms에서 fn(2)가 실행되기 전에 발생한 취소TimeMs(50ms)의 지연 후에 발생하도록 예약되어 있었으며, 그 결과 fn(2)는 호출되지 않았습니다.

예제 3:
입력: fn = (x1, x2) => x1 * x2, args = [2,4], t = 30
Output: [{"time": 30, "returned": 8}]
설명: 
const cancelTimeMs = 100;
const cancelFn = 취소 가능((x1, x2) => x1 * x2, [2,4], 30);
setTimeout(cancelFn, cancelTimeMs);

취소는 30ms에 fn(2,4)가 실행된 후 발생한 취소 시간(100ms)의 지연 후에 발생하도록 예약되었습니다.
 

제약 조건:

fn은 함수입니다.
args는 유효한 JSON 배열
1 <= args.length <= 10
20 <= t <= 1000
10 <= cancelTimeMs <= 1000

/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    const timer = setTimeout(() => fn(...args), t);
    
    const cancelFn = () => clearTimeout(timer);
    
  return cancelFn;
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 5;
 *  const args = [2], t = 20, cancelTimeMs = 50;
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
 *  const maxT = Math.max(t, cancelTimeMs);
 *           
 *  setTimeout(cancel, cancelTimeMs);
 *
 *  setTimeout(() => {
 *      console.log(result); // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */