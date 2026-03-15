# 연습문제
## 옹알이 (2)

### 문제 설명
머쓱이는 태어난 지 11개월 된 조카를 돌보고 있습니다. 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음과 네 가지 발음을 조합해서 만들 수 있는 발음밖에 하지 못하고 연속해서 같은 발음을 하는 것을 어려워합니다. 문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

### 제한사항
- 1 ≤ babbling의 길이 ≤ 100
- 1 ≤ babbling[i]의 길이 ≤ 30
- 문자열은 알파벳 소문자로만 이루어져 있습니다.

### 입출력 예
<table align="center">
	<tr>
		<td align="center"><b>babbling</b></td>
		<td align="center"><b>result</b></td>
	</tr>
	<tr>
		<td align="center">["aya", "yee", "u", "maa"]</td>
		<td align="center">1</td>
	</tr>
	<tr>
		<td align="center">["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]</td>
		<td align="center">2</td>
	</tr>
</table>

### 입출력 예 설명
입출력 예 #1

["aya", "yee", "u", "maa"]에서 발음할 수 있는 것은 "aya"뿐입니다. 따라서 1을 return합니다.
입출력 예 #2

["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]에서 발음할 수 있는 것은 "aya" + "ye" = "ayaye", "ye" + "ma" + "woo" = "yemawoo"로 2개입니다. "yeye"는 같은 발음이 연속되므로 발음할 수 없습니다. 따라서 2를 return합니다.

### 유의사항
네 가지를 붙여 만들 수 있는 발음 이외에는 어떤 발음도 할 수 없는 것으로 규정합니다. 예를 들어 "woowo"는 "woo"는 발음할 수 있지만 "wo"를 발음할 수 없기 때문에 할 수 없는 발음입니다.

---

## 뒤에 있는 큰 수 찾기

### 문제 설명
정수로 이루어진 배열 numbers가 있습니다. 배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
정수 배열 numbers가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요. 단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.

### 제한사항
- 4 ≤ numbers의 길이 ≤ 1,000,000
	- 1 ≤ numbers[i] ≤ 1,000,000

### 입출력 예
<table align="center">
	<tr>
		<td align="center"><b>numbers</b></td>
		<td align="center"><b>result</b></td>
	</tr>
	<tr>
		<td align="center">[2, 3, 3, 5]</td>
		<td align="center">[3, 5, 5, -1]</td>
	</tr>
	<tr>
		<td align="center">[9, 1, 5, 3, 6, 2]</td>
		<td align="center">[-1, 5, 6, 6, -1, -1]</td>
	</tr>
</table>

### 입출력 예 설명
입출력 예 #1

2의 뒷 큰수는 3입니다. 첫 번째 3의 뒷 큰수는 5입니다. 두 번째 3 또한 마찬가지입니다. 5는 뒷 큰수가 없으므로 -1입니다. 위 수들을 차례대로 배열에 담으면 [3, 5, 5, -1]이 됩니다.  

입출력 예 #2

9는 뒷 큰수가 없으므로 -1입니다. 1의 뒷 큰수는 5이며, 5와 3의 뒷 큰수는 6입니다. 6과 2는 뒷 큰수가 없으므로 -1입니다. 위 수들을 차례대로 배열에 담으면 [-1, 5, 6, 6, -1, -1]이 됩니다.  