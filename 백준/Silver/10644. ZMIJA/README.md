# [Silver I] ZMIJA - 10644 

[문제 링크](https://www.acmicpc.net/problem/10644) 

### 성능 요약

메모리: 3236 KB, 시간: 8 ms

### 분류

애드 혹, 다이나믹 프로그래밍, 구현

### 제출 일자

2025년 5월 6일 22:49:43

### 문제 설명

<p>Mirko is making a clone of the popular computer game "Snake". In the game, you control the movement of a snake on a screen with dimensions of R · S pixels. The objective of the game is to collect all the apples.</p>

<p>Unfortunately, Mirko’s implementation isn’t that great and the gameplay is different than the original. Here is a description of Mirko’s game:</p>

<ul>
	<li>unlike the original, the apples don’t appear randomly on the screen, but instead you know the positions of all apples at the beginning of the game</li>
	<li>at the beginning of the game, the snake is located in the lower left pixel of the screen and is facing right</li>
	<li>there are two buttons in the game, denoted with A and B</li>
	<li>when you press the button A, the snake moves forward by 1 pixel in the direction which it is currently facing. If that move would cause the snake to go off screen, nothing happens.</li>
	<li>when you press the button B, the snake moves up by 1 pixel and changes the direction it’s facing by 180°</li>
	<li>when the snake moves to a pixel containing an apple, it eats the apple but doesn’t grow like in the original game</li>
</ul>

<p>You have the following task: for given positions of apples at the beginning of the game, determine the smallest number of button presses it takes for the snake to collect all the apples.</p>

### 입력 

 <p>The first line of input contains the integers R and S (2 ≤ R, S ≤ 1 000), the height and width of the screen.</p>

<p>Each of the following R lines contains exactly S characters. These characters represent the content of the screen. Pixels with apples on them are denoted with ’J’ and empty pixels are denoted with ’.’.</p>

<p>The lower left corner contains the character ’Z’ that represents the snake in its initial position.</p>

### 출력 

 <p>The first and only line of output must contain the required minimal number of button presses.</p>

