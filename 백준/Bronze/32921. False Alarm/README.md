# [Bronze I] False Alarm - 32921 

[문제 링크](https://www.acmicpc.net/problem/32921) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

사칙연산, 구현, 수학

### 제출 일자

2025년 6월 19일 10:48:15

### 문제 설명

<p>Faina is going to sleep, but she needs to wake up early tomorrow for a very important contest. She has already set $n$ alarms at different times between 7:00 and 9:00 in the morning.</p>

<p>However, Faina is a deep sleeper. She knows that in order to wake up, she will need to hear at least three alarms within a 10-minute timespan. In other words, for some three alarms, the difference between the first and the last alarm must be 10 minutes or less.</p>

<p>Faina is not sure if the current set of alarms she has satisfies this condition, and she is worried she might oversleep the contest (and make her teammates angry!). Thus, she wants to set some additional alarms. All new alarms should also be set between 7:00 and 9:00, and all alarms, including the old ones, must be set at different times.</p>

<p>Find the smallest number of additional alarms Faina has to set to be confident that she will wake up. In particular, if she can already be sure she'll wake up, the number of additional alarms is $0$.</p>

### 입력 

 <p>The first line contains a single integer $n$, denoting the number of alarms Faina has set ($1 \le n \le 20$).</p>

<p>The $i$-th of the following $n$ lines contains the time of the $i$-th alarm in the <code>h:mm</code> format ($7 \le \mathtt{h} \le 9$; $00 \le \mathtt{mm} \le 59$; if $\mathtt{h} = 9$, then $\mathtt{mm} = 00$). The alarms are given in strictly increasing order of time.</p>

### 출력 

 <p>Print the smallest number of additional alarms Faina has to set in order to guarantee waking up.</p>

