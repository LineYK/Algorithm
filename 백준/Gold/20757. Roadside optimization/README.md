# [Gold V] Roadside optimization - 20757 

[문제 링크](https://www.acmicpc.net/problem/20757) 

### 성능 요약

메모리: 2284 KB, 시간: 16 ms

### 분류

자료 구조, 분리 집합, 그래프 이론

### 제출 일자

2025년 4월 22일 09:45:59

### 문제 설명

<p>Some of the towns in the province $G$ are connected with roads; roads always go both ways. The budget to support the road network is scarce, therefore it was decided to leave the bare minimum of the roads. However, if it is currently possible to reach the town $B$ from the town $A$, this possibility must remain even after the reduction.</p>

<p>Help to define the minimum number of roads that must remain.</p>

### 입력 

 <p>The first line of the input file contains a single integer $T$ --- the number of tests ($1 \le T \le 50\,000$). It is followed by the description of $T$ tests.</p>

<p>The first line of the test number $t$ contains a single integer $N_t$ --- the number of towns ($1 \le N_t \le 200$).</p>

<p>The following $N_t$ lines contain $N_t$ integers; each integer is either $0$ or $1$. If the line with the number $i$ has $0$ in the $j$th position, then the town $j$ can not be reached from the town $i$ (even by driving through other towns); if it is $1$, then there is a passage. It is assumed that there is a passage from a town to the same town, so there will always be $1$ in the $i$th line in the $i$th position ($1 \le i \le N_t$).</p>

<p>It is guaranteed that the sum of $N_t^2$ over all tests is not greater than $50\,000$.</p>

### 출력 

 <p>For each test, print a single integer on a separate line --- the minimum number of roads to be kept.</p>

