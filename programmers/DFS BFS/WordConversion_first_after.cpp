#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 두 단어가 변환 가능한 상태인지 확인하는 함수
bool isChange(const string& a, const string& b)
{
    int check = 0;
    for (int index = 0; index < a.length(); index++)
    {
        if (a[index] == b[index]) check = check + 1;
    }

    if (check == a.length() - 1) return true;
    else return false;
}

// 너비 우선 탐색
int BFS(const vector<string>& words, string goal, string& begin)
{
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q; // pair 값 : {현재 위치, 변환 횟수}
    q.push({ begin, 0 });

    while (q.empty() == false)
    {
        pair<string, int> now = q.front();
        q.pop();

        // while문 안전 장치
        if (now.second > 50) break;

        for (int index = 0; index < words.size(); index++)
        {
            // 이미 방문했을 경우, 패스
            if (visited[index] == true) continue;

            // 바꿀 수 없는 단어일 경우, 패스
            if (isChange(now.first, words[index]) == false) continue;

            // 바꾸는 단어가 target 단어일 경우, 변환 횟수 리턴
            if (words[index] == goal) return now.second + 1;

            // 이동 가능한 위치로 이동하여 큐에 저장
            q.push({ words[index], now.second + 1 });
            visited[index] = true;
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    // 1. target 단어가 words에 존재하는지 확인 및 없을 경우 0으로 리턴
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;

    return BFS(words, *it, begin);
}

// 문제 해결 : 진짜 너비 우선 탐색을 사용해서 불필요한 탐색 횟수를 줄여 효율성 개선
// DFS : 깊이 우선 탐색, 재귀 방식으로 끝까지 확인 후, 반환점으로 돌아와 다시 확인을 반복하며 탐색
// BFS : 너비 우선 탐색, FIFO 방식의 큐(Queue)를 사용해 가장 가까운 경로부터 확인하며 탐색