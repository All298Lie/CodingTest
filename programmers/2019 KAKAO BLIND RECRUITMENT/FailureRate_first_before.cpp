#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(const int N, vector<int> stages) {
    vector<int> answer(N, 0);
    vector<int> challenge(N + 2, 0);

    vector<float> fail(N + 1, -1.0f);

    // 1. 스테이지 기준으로, 유저가 몇 명 도착했는지 저장
    for (const auto& stage : stages) challenge[stage]++;

    // 2. 스테이지 별로 실패율이 어떻게 되는지 저장
    int people = challenge[N + 1];
    for (int index = fail.size() - 1; index > 0; index--)
    {
        people += challenge[index];

        // 실패율 = 현재 스테이지에 남은 인원 / (스테이지에 남은 인원 + 다음으로 넘어간 인원)
        fail[index] = (people == 0 ? 0.0f : (float)challenge[index] / (float)people);
    }

    // 3. 실패율이 높은 스테이지부터 배열에 저장
    for (auto& result : answer)
    {
        int index = max_element(fail.begin(), fail.end()) - fail.begin();

        result = index;
        fail[index] = -1.0f;
    }

    return answer;
}