# [Silver II] Light Up - 32504 

[문제 링크](https://www.acmicpc.net/problem/32504) 

### 성능 요약

메모리: 109544 KB, 시간: 92 ms

### 분류

그래프 이론, 구현, 시뮬레이션

### 제출 일자

2025년 9월 21일 21:49:18

### 문제 설명

<p>Light Up is a pencil puzzle. Your job will not be to play Light Up, but simply to judge whether a player’s solution is correct.</p>

<p>The game is played on a square grid. Some of the cells are blocked, and some of the blocked cells have a number from $0$ to $4$. The player must place light bulbs in open cells. Each light bulb can light all of the open cells above, below, left, and right (but not diagonally) until the light reaches the edge of the grid or a blocked cell. The player must place light bulbs so that:</p>

<ul>
	<li>Every open cell is lit.</li>
	<li>No two light bulbs can shine on each other.</li>
	<li>Any blocked cell with a number in it must have exactly that number of light bulbs immediately adjacent above, below, left, or right. Diagonals do not count.</li>
</ul>

<p>The following is an example grid with its solution:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/18a0de3c-75f7-42c8-965a-9a8b279f5095/-/preview/"></p>

<p>Given a grid with light bulbs placed, determine whether it is, in fact, a solution. Note that if a grid has no open cells, and does not violate any other constraints, it is trivially solved.</p>

### 입력 

 <p>The first line of input contains a single integer $n$ ($1≤n≤30$), which is the number of rows and columns in the grid.</p>

<p>Each of the next $n$ lines contains exactly $n$ characters from the set {‘<code>.</code>’,‘<code>X</code>’,‘<code>?</code>’,‘<code>0</code>’,‘<code>1</code>’,‘<code>2</code>’,‘<code>3</code>’,‘<code>4</code>’}. This is the grid, with ‘<code>.</code>’ representing an open cell, ‘<code>X</code>’ representing a blocked cell, ‘<code>?</code>’ representing a light bulb, and the numbers ‘<code>0</code>’,‘<code>1</code>’,‘<code>2</code>’,‘<code>3</code>’,‘<code>4</code>’ representing a blocked cell with a constraint on the number of adjacent light bulbs.</p>

### 출력 

 <p>Output a single integer, which is $1$ if the input is a valid solution, and $0$ otherwise.</p>

