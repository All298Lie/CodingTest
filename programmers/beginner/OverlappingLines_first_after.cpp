#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;

    // 1. 선분을 점의 좌표와 선의 증감으로 분리 표현
    vector<pair<int, int>> events;
    for (auto& line : lines)
    {
        events.push_back({ line[0], 1 }); // 선분의 시작점. 이 이후로 선 개수가 증가됨
        events.push_back({ line[1], -1 }); // 선분의 끝점. 이 이후로 선 개수가 감소됨
    }

    // 2. 좌표를 기준으로 오름차순 정렬
    sort(events.begin(), events.end()); 

    int activeLines = 0;
    int lastPoint = events[0].first;

    // 3. 정렬된 이벤트를 순서대로 스윕
    for (auto& event : events)
    {
        if (activeLines >= 2 ) // 겹쳐있던 선분이 2개 이상이었을 경우, 길이만큼 추가
        {
            answer = answer + event.first - lastPoint;
        }

        // 선분 개수 갱신 및 현재 위치 저장
        activeLines = activeLines + event.second;
        lastPoint = event.first;
    }

    return answer;
}

// 문제 해결 :
// 기존에 생각했던 방식의 선분의 점과 점을 넘어들며 선분이 겹쳐있을 경우 선분의 길이만큼 더하는 방식이 기하에서 사용되는 라인 스위핑 알고리즘으로,
// 좌표와 해당 좌표에 일어난 이벤트(선의 증감)를 쌓아 정렬하여, 선이 2개 겹치는 구간을 마지막 탐색 좌표와 현재 탐색 좌표를 통해 선분의 길이를 구하여 계산하는 문제였음

// 해당 문제를 통해 라인 스위핑이란 알고리즘을 알게되어 좋은 계기가 되었다고 생각함