#include <vector>

using namespace std;

// 깊이 우선 탐색
void DFS(vector<bool>& visited, const vector<vector<int>>& computers, int point)
{
    if (visited[point] == true) return;

    visited[point] = true;

    for (int i = 0; i < computers[point].size(); i++)
    {
        if (computers[point][i] == 1)
        {
            if (visited[i] == true) continue;

            DFS(visited, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // 1. 컴퓨터 방문 확인
    vector<bool> visited(n, false);

    // 2. DFS를 사용하여 컴퓨터의 네트워크 확인
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true) continue;

        // 3. 확인되지 않은 컴퓨터일 경우 새로운 네트워크이므로 네트워크 수 증가 및 탐색
        answer++;
        DFS(visited, computers, i);
    }

    return answer;
}

// 문제 해결 : 기존에 유니온-파인드 알고리즘을 통해 해결하여 이번에는 DFS 알고리즘을 통해 문제 해결