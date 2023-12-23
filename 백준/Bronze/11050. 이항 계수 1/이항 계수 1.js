/*
이항 계수 1
 
시간 제한	메모리 제한	
1 초	256 MB	

문제
자연수 
\(N\)과 정수 
\(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
\(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 10, 0 ≤ \(K\) ≤ \(N\))

출력
\(\binom{N}{K}\)를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

"use strict";
// Common Template Starts //
// 입력 코드
process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});

process.stdin.on("end", (_) => {
    inputString = inputString
        .trim()
        .split("\n")
        .map((string) => {
            return string.trim();
        });

    main();
});

function readline() {
    return inputString[currentLine++];
}
// Common Template Ends //


function main() {
    let inputs = readline().split(' ').map(Number);

    const N = inputs[0], K = inputs[1];

    console.log(factorial(N)/(factorial(K) * factorial(N-K)));
}

function factorial(n) {
    if (n === 1 || n === 0) return 1;

    return factorial(n - 1) * n;
}

