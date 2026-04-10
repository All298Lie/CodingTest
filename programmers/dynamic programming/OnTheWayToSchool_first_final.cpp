#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // 맵 생성
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));

    // 물이 담긴 지역 표시
    for (auto& puddle : puddles)
    {
        map[puddle.back() - 1][puddle.front() - 1] = -1;
    }

    // 집부터 경우의 수 1로 시작
    map[0][0] = 1;

    // 맵 전체 탐색
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (map[row][col] < 0) continue; // 현재 위치가 물에 잠긴 지역일 경우, 패스

            if (map[row + 1][col] >= 0) // 아래 지역이 물에 잠기지 않았을 경우
            {
                map[row + 1][col] = (map[row + 1][col] + map[row][col]) % 1'000'000'007;
            }

            if (map[row][col + 1] >= 0) // 오른쪽 지역이 물에 잠기지 않았을 경우
            {
                map[row][col + 1] = (map[row][col + 1] + map[row][col]) % 1'000'000'007;
            }
        }
    }

    return map[n - 1][m - 1];
}

// 문제해결 : DP 알고리즘 (Push DP)
// 동적 계획법을 사용하여 집부터 학교까지 이동할 수 있는 경우의 수를 누적하는 방식을 사용
// 현재 위치의 경우의 수를 이동 가능한 다음 위치에 더해주는 Push DP 기법을 사용하여 O(m*n)만에 최단 경로의 수를 계산함.

// 트러블슈팅 및 최적화
// 1. 오버플로우 방지와 모듈러 연산의 위치 최적화
// 경우의 수가 기하급수적으로 커져 int 자료형의 범위를 초과할 수 있음
// 값을 누적하는 매 순간 (현재값 + 이전값) % 1'000'000'007 연산을 수행하여 데이터의 안정성을 보장함
// 
// 2. 캐시 메모리 효율
// C++의 2차원 배열은 가로(row) 단위로 메모리에 연속 할당이 됨. 따라서 열을 먼저 순회하면 메모리를 띄엄띄엄 읽게되어 CPU 캐시 효율이 저하됨
// 따라서 띄엄띄엄 읽지 않도록 이중 for문을 구성해주면 메모리를 순차적으로 접근하게 되어 하드웨어 레벨의 연산 속도가 극대화됨
//
// 3. 배열 패딩을 통한 분기문 최적화
// 맵 크기를 n + 1, m + 1로 여유있게 할당하여, 다음 칸으로 이동할 때 발생하는 범위 초과 에러를 방어함. 이로 인해 불필요한 경계 검사 if문을 제거하여 코드를 간결화함.