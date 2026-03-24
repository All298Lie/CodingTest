#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 깊이 우선 탐색
void DFS(const vector<string>& words, vector<bool> visited, int goal, string& begin, int search, int count, int& answer)
{
    // 이미 방문했을 경우, 리턴
    if (visited[search] == true) return;

    // 이미 탐색된 가장 짧은 변환 과정보다 탐색이 길 경우, 리턴
    if (answer <= count + 1) return;

    // 1. 단어가 몇개 일치하는지 확인
    int check = 0;
    for (int index = 0; index < begin.length(); index++)
    {
        if (words[search][index] == begin[index]) check = check + 1;
    }

    // 단어가 1개만 일치하지 않아야 단어를 바꿀 수 있으므로 아닐 경우, 리턴
    if (check != begin.length() - 1) return;

    // 바꿀 수 있을 경우, 다음 단어가 target 단어일 경우, 현재까지 변환한 횟수가 기존 값보다 적을 때 값 변경 후 리턴
    if (words[search] == words[goal])
    {
        answer = min(answer, count + 1);
        return;
    }

    // 2. 방문 처리 및 변환한 다른 단어 탐색
    visited[search] = true;
    for (int index = 0; index < words.size(); index++)
    {
        if (index == search) continue; // 본인 제외

        string change = words[search];

        DFS(words, visited, goal, change, index, count + 1, answer); // 너비 우선 탐색
    }

    // visited[search] = false; // 해당 코드를 넣으면 끝까지 확인 후, 돌아갈때 탐색했던 기록을 지우게 됨. (백트래킹)
}

int solution(string begin, string target, vector<string> words)
{
    // 1. target 단어가 단어 집합에 존재하는지 확인 및 없을 경우 0으로 리턴
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;

    int answer = 51; // 최대 변환 값 : 50 (값이 51로 남아있을 경우 변환 할 수 없는 판정)
    int goal = it - words.begin(); // 단어 집합에서 target 단어의 인덱스 값
    vector<bool> visited(words.size(), 0);

    // 2. 시작 지점을 다르게 하여 단어 탐색
    for (int index = 0; index < words.size(); index++)
    {
        DFS(words, visited, goal, begin, index, 0, answer); // 너비 우선 탐색
    }

    // 가장 짧은 변환 횟수를 리턴(출력)
    if (answer == 51) return 0;
    else return answer;
}

// 문제 해결 : 깊이 우선 탐색 방식을 사용하여 지금까지 탐색한 길이보다 길 경우 바로 리턴하여 더이상의 탐색을 막는 방식 사용
// 피드백 : 깊이 우선 탐색과 너비 우선 탐색을 헷갈려서 재귀 방식을 사용하여 깊이 우선 탐색이 되어버림. (초기 함수명 : BFS())
// + 깊이 우선 탐색에서 방문을 기록하는 배열이 복사 참조되고 있음.
// 백트래킹 기법을 사용하여 탐색이 끝나면 본인의 방문 기록을 지워주면 배열을 복사하지 않아도 됨.