# 2018 KAKAO BLIND RECUITMENT
## [1차] 뉴스 클러스터링
여러 언론사에서 쏟아지는 뉴스, 특히 속보성 뉴스를 보면 비슷비슷한 제목의 기사가 많아 정작 필요한 기사를 찾기가 어렵다. Daum 뉴스의 개발 업무를 맡게 된 신입사원 튜브는 사용자들이 편리하게 다양한 뉴스를 찾아볼 수 있도록 문제점을 개선하는 업무를 맡게 되었다.  

개발의 방향을 잡기 위해 튜브는 우선 최근 화제가 되고 있는 "카카오 신입 개발자 공채" 관련 기사를 검색해보았다.  

카카오 첫 공채..'블라인드' 방식 채용  
카카오, 합병 후 첫 공채.. 블라인드 전형으로 개발자 채용  
카카오, 블라인드 전형으로 신입 개발자 공채  
카카오 공채, 신입 개발자 코딩 능력만 본다  
카카오, 신입 공채.. "코딩 실력만 본다"  
카카오 "코딩 능력만으로 2018 신입 개발자 뽑는다"  
기사의 제목을 기준으로 "블라인드 전형"에 주목하는 기사와 "코딩 테스트"에 주목하는 기사로 나뉘는 걸 발견했다. 튜브는 이들을 각각 묶어서 보여주면 카카오 공채 관련 기사를 찾아보는 사용자에게 유용할 듯싶었다.  

유사한 기사를 묶는 기준을 정하기 위해서 논문과 자료를 조사하던 튜브는 "자카드 유사도"라는 방법을 찾아냈다.  

자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다. 두 집합 `A`, `B` 사이의 자카드 유사도 `J(A, B)`는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.  

예를 들어 집합 `A` = {1, 2, 3}, 집합 `B` = {2, 3, 4}라고 할 때, 교집합 `A ∩ B` = {2, 3}, 합집합 `A ∪ B` = {1, 2, 3, 4}이 되므로, 집합 `A`, `B` 사이의 자카드 유사도 `J(A, B)` = 2/4 = 0.5가 된다.   집합 `A`와 집합 `B`가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 `J(A, B)` = 1로 정의한다.

자카드 유사도는 원소의 중복을 허용하는 다중집합에 대해서 확장할 수 있다. 다중집합 `A`는 원소 "1"을 3개 가지고 있고, 다중집합 `B`는 원소 "1"을 5개 가지고 있다고 하자. 이 다중집합의 교집합 `A ∩ B`는 원소 "1"을 min(3, 5)인 3개, 합집합 `A ∪ B`는 원소 "1"을 max(3, 5)인 5개 가지게 된다. 다중집합 `A` = {1, 1, 2, 2, 3}, 다중집합 `B` = {1, 2, 2, 4, 5}라고 하면, 교집합 `A ∩ B` = {1, 2, 2}, 합집합 `A ∪ B` = {1, 1, 2, 2, 3, 4, 5}가 되므로, 자카드 유사도 `J(A, B)` = 3/7, 약 0.42가 된다.  

이를 이용하여 문자열 사이의 유사도를 계산하는데 이용할 수 있다. 문자열 "FRANCE"와 "FRENCH"가 주어졌을 때, 이를 두 글자씩 끊어서 다중집합을 만들 수 있다. 각각 {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}가 되며, 교집합은 {FR, NC}, 합집합은 {FR, RA, AN, NC, CE, RE, EN, CH}가 되므로, 두 문자열 사이의 자카드 유사도 `J("FRANCE", "FRENCH")` = 2/8 = 0.25가 된다.  

### 입력 형식
입력으로는 str1과 str2의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.  
입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다. 이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.  
다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. "AB"와 "Ab", "ab"는 같은 원소로 취급한다.  

### 출력 형식
입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.  

### 예제 입출력
<table align="center">
	<tr>
		<td align="center"><b>str1</b></td>
		<td align="center"><b>str2</b></td>
		<td align="center"><b>anwer</b></td>
	</tr>
	<tr>
		<td align="center">FRANCE</td>
		<td align="center">french</td>
		<td align="center">16384</td>
	</tr>
	<tr>
		<td align="center">handshake</td>
		<td align="center">shake hands</td>
		<td align="center">65536</td>
	</tr>
	<tr>
		<td align="center">aa1+aa2</td>
		<td align="center">AAAA12</td>
		<td align="center">43690</td>
	</tr>
	<tr>
		<td align="center">E=M*C^2</td>
		<td align="center">e=m*c^2</td>
		<td align="center">65536</td>
	</tr>
</table>
[해설보러가기](http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/)

---

## [3차] n진수 게임
### 문제 설명
튜브가 활동하는 코딩 동아리에서는 전통적으로 해오는 게임이 있다. 이 게임은 여러 사람이 둥글게 앉아서 숫자를 하나씩 차례대로 말하는 게임인데, 규칙은 다음과 같다.

  1. 숫자를 0부터 시작해서 차례대로 말한다. 첫 번째 사람은 0, 두 번째 사람은 1, … 열 번째 사람은 9를 말한다.
  2. 10 이상의 숫자부터는 한 자리씩 끊어서 말한다. 즉 열한 번째 사람은 10의 첫 자리인 1, 열두 번째 사람은 둘째 자리인 0을 말한다.

이렇게 게임을 진행할 경우,
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, …  
순으로 숫자를 말하면 된다.  

한편 코딩 동아리 일원들은 컴퓨터를 다루는 사람답게 이진수로 이 게임을 진행하기도 하는데, 이 경우에는  
0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, …  
순으로 숫자를 말하면 된다.  

이진수로 진행하는 게임에 익숙해져 질려가던 사람들은 좀 더 난이도를 높이기 위해 이진법에서 십육진법까지 모든 진법으로 게임을 진행해보기로 했다. 숫자 게임이 익숙하지 않은 튜브는 게임에 져서 벌칙을 받는 굴욕을 피하기 위해, 자신이 말해야 하는 숫자를 스마트폰에 미리 출력해주는 프로그램을 만들려고 한다. 튜브의 프로그램을 구현하라.  

### 입력 형식
진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p 가 주어진다.  

  - 2 ≦ n ≦ 16
  - 0 ＜ t ≦ 1000
  - 2 ≦ m ≦ 100
  - 1 ≦ p ≦ m

### 출력 형식
튜브가 말해야 하는 숫자 t개를 공백 없이 차례대로 나타낸 문자열. 단, 10~15는 각각 대문자 A~F로 출력한다.  

### 예제 입출력
<table align="center">
	<tr>
		<td align="center"><b>n</b></td>
		<td align="center"><b>t</b></td>
		<td align="center"><b>m</b></td>
		<td align="center"><b>p</b></td>
		<td align="center"><b>result</b></td>
	</tr>
	<tr>
		<td align="center">2</td>
		<td align="center">4</td>
		<td align="center">2</td>
		<td align="center">1</td>
		<td align="center">"0111"</td>
	</tr>
	<tr>
		<td align="center">16</td>
		<td align="center">16</td>
		<td align="center">2</td>
		<td align="center">1</td>
		<td align="center">"02468ACE11111111"</td>
	</tr>
	<tr>
		<td align="center">16</td>
		<td align="center">16</td>
		<td align="center">2</td>
		<td align="center">2</td>
		<td align="center">"13579BDF01234567"</td>
	</tr>
</table>
[해설보러가기](http://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/)

---

## [3차] 압축
### 문제 설명
신입사원 어피치는 카카오톡으로 전송되는 메시지를 압축하여 전송 효율을 높이는 업무를 맡게 되었다. 메시지를 압축하더라도 전달되는 정보가 바뀌어서는 안 되므로, 압축 전의 정보를 완벽하게 복원 가능한 무손실 압축 알고리즘을 구현하기로 했다.  

어피치는 여러 압축 알고리즘 중에서 성능이 좋고 구현이 간단한 LZW(Lempel–Ziv–Welch) 압축을 구현하기로 했다. LZW 압축은 1983년 발표된 알고리즘으로, 이미지 파일 포맷인 GIF 등 다양한 응용에서 사용되었다.  

LZW 압축은 다음 과정을 거친다.  

  1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.  
  2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.  
  3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.  
  4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.  
  5. 단계 2로 돌아간다.  

압축 알고리즘이 영문 대문자만 처리한다고 할 때, 사전은 다음과 같이 초기화된다. 사전의 색인 번호는 정수값으로 주어지며, 1부터 시작한다고 하자.  

<table align="center">
	<tr>
		<td align="center"><b>색인 번호</b></td>
		<td align="center"><b>1</b></td>
		<td align="center"><b>2</b></td>
		<td align="center"><b>3</b></td>
		<td align="center"><b>...</b></td>
		<td align="center"><b>24</b></td>
		<td align="center"><b>25</b></td>
		<td align="center"><b>26</b></td>
	</tr>
	<tr>
		<td align="center">단어</td>
		<td align="center">A</td>
		<td align="center">B</td>
		<td align="center">C</td>
		<td align="center">...</td>
		<td align="center">X</td>
		<td align="center">Y</td>
		<td align="center">Z</td>
	</tr>
</table>

예를 들어 입력으로 KAKAO가 들어온다고 하자.  

  1. 현재 사전에는 KAKAO의 첫 글자 K는 등록되어 있으나, 두 번째 글자까지인 KA는 없으므로, 첫 글자 K에 해당하는 색인 번호 11을 출력하고, 다음 글자인 A를 포함한 KA를 사전에 27 번째로 등록한다.
  2. 두 번째 글자 A는 사전에 있으나, 세 번째 글자까지인 AK는 사전에 없으므로, A의 색인 번호 1을 출력하고, AK를 사전에 28 번째로 등록한다.
  3. 세 번째 글자에서 시작하는 KA가 사전에 있으므로, KA에 해당하는 색인 번호 27을 출력하고, 다음 글자 O를 포함한 KAO를 29 번째로 등록한다.
  4. 마지막으로 처리되지 않은 글자 O에 해당하는 색인 번호 15를 출력한다.

<table align="center">
	<tr>
		<td align="center"><b>현재 입력(w)</b></td>
		<td align="center"><b>다음 글자(c)</b></td>
		<td align="center"><b>출력</b></td>
		<td align="center"><b>사전 추가(w+c)</b></td>
	</tr>
	<tr>
		<td align="center">K</td>
		<td align="center">A</td>
		<td align="center">11</td>
		<td align="center">27 : KA</td>
	</tr>
	<tr>
		<td align="center">A</td>
		<td align="center">K</td>
		<td align="center">1</td>
		<td align="center">28 : AK</td>
	</tr>
	<tr>
		<td align="center">KA</td>
		<td align="center">O</td>
		<td align="center">27</td>
		<td align="center">29 : KAO</td>
	</tr>
	<tr>
		<td align="center">O</td>
		<td align="center"></td>
		<td align="center">15</td>
		<td align="center"></td>
	</tr>
</table>

이 과정을 거쳐 다섯 글자의 문장 `KAKAO`가 4개의 색인 번호 [11, 1, 27, 15]로 압축된다.

입력으로 `TOBEORNOTTOBEORTOBEORNOT`가 들어오면 다음과 같이 압축이 진행된다.

<table align="center">
	<tr>
		<td align="center"><b>현재 입력(w)</b></td>
		<td align="center"><b>다음 글자(c)</b></td>
		<td align="center"><b>출력</b></td>
		<td align="center"><b>사전 추가(w+c)</b></td>
	</tr>
	<tr>
		<td align="center">T</td>
		<td align="center">O</td>
		<td align="center">20</td>
		<td align="center">27 : TO</td>
	</tr>
	<tr>
		<td align="center">O</td>
		<td align="center">B</td>
		<td align="center">15</td>
		<td align="center">28 : OB</td>
	</tr>
	<tr>
		<td align="center">B</td>
		<td align="center">E</td>
		<td align="center">2</td>
		<td align="center">29 : BE</td>
	</tr>
	<tr>
		<td align="center">E</td>
		<td align="center">O</td>
		<td align="center">5</td>
		<td align="center">30 : EO</td>
	</tr>
	<tr>
		<td align="center">O</td>
		<td align="center">R</td>
		<td align="center">15</td>
		<td align="center">31 : OR</td>
	</tr>
	<tr>
		<td align="center">R</td>
		<td align="center">N</td>
		<td align="center">18</td>
		<td align="center">32 : RN</td>
	</tr>
	<tr>
		<td align="center">N</td>
		<td align="center">O</td>
		<td align="center">14</td>
		<td align="center">33 : NO</td>
	</tr>
	<tr>
		<td align="center">O</td>
		<td align="center">T</td>
		<td align="center">15</td>
		<td align="center">34 : OT</td>
	</tr>
	<tr>
		<td align="center">T</td>
		<td align="center">T</td>
		<td align="center">20</td>
		<td align="center">35 : TT</td>
	</tr>
	<tr>
		<td align="center">TO</td>
		<td align="center">B</td>
		<td align="center">27</td>
		<td align="center">36 : TOB</td>
	</tr>
	<tr>
		<td align="center">BE</td>
		<td align="center">O</td>
		<td align="center">29</td>
		<td align="center">37 : BEO</td>
	</tr>
	<tr>
		<td align="center">OR</td>
		<td align="center">T</td>
		<td align="center">31</td>
		<td align="center">38 : ORT</td>
	</tr>
	<tr>
		<td align="center">TOB</td>
		<td align="center">E</td>
		<td align="center">36</td>
		<td align="center">39 : TOBE</td>
	</tr>
	<tr>
		<td align="center">EO</td>
		<td align="center">R</td>
		<td align="center">30</td>
		<td align="center">40 : EOR</td>
	</tr>
	<tr>
		<td align="center">RN</td>
		<td align="center">O</td>
		<td align="center">32</td>
		<td align="center">41 : RNO</td>
	</tr>
	<tr>
		<td align="center">OT</td>
		<td align="center"></td>
		<td align="center">34</td>
		<td align="center"></td>
	</tr>
</table>

### 입력 형식
입력으로 영문 대문자로만 이뤄진 문자열 msg가 주어진다. msg의 길이는 1 글자 이상, 1000 글자 이하이다.

### 출력 형식
주어진 문자열을 압축한 후의 사전 색인 번호를 배열로 출력하라.

### 예제 입출력
<table align="center">
	<tr>
		<td align="center"><b>msg</b></td>
		<td align="center"><b>answer</b></td>
	</tr>
	<tr>
		<td align="center">KAKAO</td>
		<td align="center">[11, 1, 27, 15]</td>
	</tr>
	<tr>
		<td align="center">TOBEORNOTTOBEORTOBEORNOT</td>
		<td align="center">[20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]</td>
	</tr>
	<tr>
		<td align="center">ABABABABABABABAB</td>
		<td align="center">[1, 2, 27, 29, 28, 31, 30]</td>
	</tr>
</table>
[해설보러가기](http://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/)