# [Silver II] RPG 마스터 오명진 - 22941 

[문제 링크](https://www.acmicpc.net/problem/22941) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2025년 3월 4일 15:34:52

### 문제 설명

<p>소프트웨어학부에 재학중인 명진이는 요즘 방역 수칙을 지키기 위해 게임을 하고있다. 그러나 모든 RPG를 다 클리어해버린 명진이는 자신이 직접 RPG를 만들기로 결심한다. 게임은 용사와 마왕의 전투로 이루어진다. 용사와 마왕은 각각 공격력(ATK)과 체력(HP)을 가지고있다. 또한 게임이 단조로워지는 것을 방지하기 위하여, 명진이는 마왕에게 스킬을 선물했다. 마왕의 체력이 1이상 P 이하로 떨어지게 되면 <strong><u>1번에 한해</u></strong> S만큼 체력을 회복한다! 명진이의 게임은 다음과 같이 진행된다.</p>

<ol>
	<li>용사의 공격력만큼 마왕의 체력을 깎습니다.</li>
	<li>마왕의 체력이 0 이하이면 용사가 승리하고 게임이 종료됩니다.</li>
	<li>마왕의 공격력만큼 용사의 체력을 깎습니다.</li>
	<li>용사의 체력이 0 이하이면 용사가 패배하고 게임이 종료됩니다.</li>
	<li>마왕의 체력이 1 이상 P 이하일 경우 S만큼의 체력을 회복합니다.</li>
	<li>게임이 종료 될 때까지 (1~5)의 과정을 반복합니다.</li>
</ol>

<p>명진이는 자신이 만든 게임의 난이도를 테스트해보고 싶어졌다. 게임을 만드는데 지친 명진이를 도와 용사가 마왕을 이길 수 있을 지 알려주는 프로그램을 만들어주자!</p>

### 입력 

 <p>첫째 줄에 <em>HP<sub>용사</sub>와 ATK<sub>용사</sub>, HP<sub>마왕</sub>, ATK<sub>마왕</sub></em> 이 주어진다.</p>

<p>용사와 마왕의 체력과 공격력은 2<sup>31</sup> -1 이하의 자연수이다.</p>

<p>둘째 줄에 마왕의 스킬 발동 시점<em> P</em> (1 ≤ <em>P</em> < <em>HP<sub>마왕</sub></em>) 과 회복량 <em>S(1 ≤ S ≤ HP<sub>마왕</sub>)</em>이 주어진다.</p>

### 출력 

 <p>첫 째 줄에 용사의 승리 여부를 출력한다.</p>

<p>용사가 승리하면 <code>"Victory!", </code>패배하면 <code>"gg"를</code> 출력한다.</p>

