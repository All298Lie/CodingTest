#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;

    // 1. 시작점과 끝점 확인
    int first_point = lines[0][0]; // 시작점
    int last_point = lines[0][1]; // 끝점
    for (int index = 1; index < lines.size(); index++)
    {
        first_point = min(first_point, lines[index][0]);
        last_point = max(last_point, lines[index][1]);
    }

    // 2. first_point부터 last_point까지 순회하며 선분이 겹치는지 확인
    for (int point = first_point; point < last_point; point++)
    {
        int check = 0; // 선분이 겹치는지 확인할때 사용할 변수

        for (auto line : lines) // 선분 순회
        {
            // point부터 point + 1까지 잇는 선분과 해당 선분이 겹칠 경우, 체크
            if (line[0] <= point && line[1] >= point + 1)
            {
                check = check + 1;
            }

            if (check >= 2) break; // 2개 이상일 경우, 선분이 이미 겹치므로 빠르게 탈출
        }

        // 체크가 2개이상 일경우, 겹치는 선분이 존재하므로 추가
        if (check >= 2) answer = answer + 1;
    }

    return answer;
}

// 문제 해결 :
// 세 선분의 시작점을 비교해서 가장 낮은 시작점을 시발점으로 하고, 가장 높은 끝점을 종착점으로 하여 탐색을 진행.
// 점을 기준으로 탐색을 하여, 현재 점과 다음 점을 잇는 선분과 겹치는 선분이 존재할 경우, 체크하여 겹치는 선분 2개가 존재할 경우 결과값 1 증가하도록 함

// 기존에 생각했던 방식은 시발점을 찾고, 겹치는 선분이 존재할 경우 두 선분의 끝점 중 낮은 끝점까지의 길이를 구해서 결과값에 반영하고 해당 끝점을 시발점으로 하여 종착점까지 다시 탐색하는 알고리즘을 구상했음
// -> 당장 코드 구현하기엔 복잡해질거같아 간단한 구조로 완성시켜버림