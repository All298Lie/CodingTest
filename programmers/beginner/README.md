# 코딩테스트 입문
## 안전지대

### 문제 설명
다음 그림과 같이 지뢰가 있는 지역과 지뢰에 인접한 위, 아래, 좌, 우 대각선 칸을 모두 위험지역으로 분류합니다.  
<image url="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/124a2c93-da99-4643-96a8-292bb871f553/image.png">
지뢰는 2차원 배열 board에 1로 표시되어 있고 board에는 지뢰가 매설 된 지역 1과, 지뢰가 없는 지역 0만 존재합니다.  
지뢰가 매설된 지역의 지도 board가 매개변수로 주어질 때, 안전한 지역의 칸 수를 return하도록 solution 함수를 완성해주세요.
### 제한사항
- board는 n * n 배열입니다.
- 1 ≤ n ≤ 100
- 지뢰는 1로 표시되어 있습니다.
- board에는 지뢰가 있는 지역 1과 지뢰가 없는 지역 0만 존재합니다.

### 입출력 예
<table align="center">
	<tr>
		<td align="center"><b>board</b></td>
		<td align="center"><b>result</b></td>
	</tr>
	<tr>
		<td align="center">[[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]</td>
		<td align="center">16</td>
	</tr>
	<tr>
		<td align="center">[[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 0]]</td>
		<td align="center">13</td>
	</tr>
	<tr>
		<td align="center">[[1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1]]</td>
		<td align="center">0</td>
	</tr>
</table>

### 입출력 예 설명
입출력 예 #1

- (3, 2)에 지뢰가 있으므로 지뢰가 있는 지역과 지뢰와 인접한 위, 아래, 좌, 우, 대각선 총 8칸은 위험지역입니다. 따라서 16을 return합니다.  
입출력 예 #2

- (3, 2), (3, 3)에 지뢰가 있으므로 지뢰가 있는 지역과 지뢰와 인접한 위, 아래, 좌, 우, 대각선은 위험지역입니다. 따라서 위험지역을 제외한 칸 수 13을 return합니다.

입출력 예 #3

- 모든 지역에 지뢰가 있으므로 안전지역은 없습니다. 따라서 0을 return합니다.

---

## 겹치는 선분의 길이

### 문제 설명
선분 3개가 평행하게 놓여 있습니다. 세 선분의 시작과 끝 좌표가 [[start, end], [start, end], [start, end]] 형태로 들어있는 2차원 배열 lines가 매개변수로 주어질 때, 두 개 이상의 선분이 겹치는 부분의 길이를 return 하도록 solution 함수를 완성해보세요.

lines가 [[0, 2], [-3, -1], [-2, 1]]일 때 그림으로 나타내면 다음과 같습니다.

<table align="center">
	<tr>
		<td><image src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/e4122d8b-9ce2-49ce-a360-3d1284babd8a/line_2.png"></td>
	</tr>
</table>

선분이 두 개 이상 겹친 곳은 [-2, -1], [0, 1]로 길이 2만큼 겹쳐있습니다.

### 제한사항
- lines의 길이 = 3
- lines의 원소의 길이 = 2
- 모든 선분은 길이가 1 이상입니다.
- lines의 원소는 [a, b] 형태이며, a, b는 각각 선분의 양 끝점 입니다.
  - -100 ≤ a < b ≤ 100

### 입출력 예
<table align="center">
	<tr>
		<td align="center"><b>lines</b></td>
		<td align="center"><b>result</b></td>
	</tr>
	<tr>
		<td align="center">[[0, 1], [2, 5], [3, 9]]</td>
		<td align="center">2</td>
	</tr>
	<tr>
		<td align="center">[[-1, 1], [1, 3], [3, 9]]</td>
		<td align="center">0</td>
	</tr>
	<tr>
		<td align="center">[[0, 5], [3, 9], [1, 10]]</td>
		<td align="center">8</td>
	</tr>
</table>

### 입출력 예 설명
입출력 예 #1

- 두 번째, 세 번째 선분 [2, 5], [3, 9]가 [3, 5] 구간에 겹쳐있으므로 2를 return 합니다.  

입출력 예 #2

- 겹친 선분이 없으므로 0을 return 합니다.  

입출력 예 #3

- 첫 번째와 두 번째 선분이 [3, 5] 구간에서 겹칩니다.
- 첫 번째와 세 번째 선분 [1, 5] 구간에서 겹칩니다.
- 두 번째와 세 번째 선분 [3, 9] 구간에서 겹칩니다.
- 따라서 [1, 9] 구간에 두 개 이상의 선분이 겹쳐있으므로, 8을 return 합니다.