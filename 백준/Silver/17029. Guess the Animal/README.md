# [Silver III] Guess the Animal - 17029 

[문제 링크](https://www.acmicpc.net/problem/17029) 

### 성능 요약

메모리: 2688 KB, 시간: 12 ms

### 분류

구현, 자료 구조, 문자열, 브루트포스 알고리즘, 집합과 맵, 해시를 사용한 집합과 맵

### 제출 일자

2025년 6월 13일 09:49:55

### 문제 설명

<p>When bored of playing their usual shell game, Bessie the cow and her friend Elsie like to play another common game called "guess the animal".</p>

<p>Initially, Bessie thinks of some animal (most of the time, this animal is a cow, making the game rather boring, but occasionally Bessie is creative and thinks of something else). Then Elsie proceeds to ask a series of questions to figure out what animal Bessie has selected. Each question asks whether the animal has some specific characteristic, and Bessie answers each question with "yes" or "no". For example:</p>

<pre>Elsie: "Does the animal fly?" 
Bessie: "No" 
Elsie: "Does the animal eat grass?" 
Bessie: "Yes" 
Elsie: "Does the animal make milk?"
Bessie: "Yes" 
Elsie: "Does the animal go moo?"
Bessie: "Yes" 
Elsie: "In that case I think the animal is a cow." 
Bessie: "Correct!"
</pre>

<p>If we call the "feasible set" the set of all animals with characteristics consistent with Elsie's questions so far, then Elsie keeps asking questions until the feasible set contains only one animal, after which she announces this animal as her answer. In each question, Elsie picks a characteristic of some animal in the feasible set to ask about (even if this characteristic might not help her narrow down the feasible set any further). She never asks about the same characteristic twice.</p>

<p>Given all of the animals that Bessie and Elsie know as well as their characteristics, please determine the maximum number of "yes" answers Elsie could possibly receive before she knows the right animal.</p>

### 입력 

 <p>The first line of input contains the number of animals, $N$ ($2 \leq N \leq 100$). Each of the next $N$ lines describes an animal. The line starts with the animal name, then an integer $K$ ($1 \leq K \leq 100$), then $K$ characteristics of that animal. Animal names and characteristics are strings of up to 20 lowercase characters (a..z). No two animals have exactly the same characteristics.</p>

### 출력 

 <p>Please output the maximum number of "yes" answers Elsie could receive before the game ends.</p>

