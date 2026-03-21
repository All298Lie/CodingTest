#include <vector>
#include <algorithm>

using namespace std;

// {스테이지, 실패율} 페어를 가진 배열의 정렬에 사용하기 위한 함수
bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
    // 값이 같을 경우 낮은 스테이지 우선
    if (a.second == b.second) return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(const int N, vector<int> stages) {
    vector<int> answer;
    vector<int> challenge(N + 2, 0);
    vector<pair<int, double>> fail;

    // 1. 스테이지 기준으로, 유저가 몇 명 도착했는지 저장
    for (const auto& stage : stages) challenge[stage]++;

    // 2. 스테이지 별로 실패율이 어떻게 되는지 저장
    int people = challenge[N + 1];
    for (int index = N; index > 0; index--)
    {
        people += challenge[index];

        // 실패율 = 현재 스테이지에 남은 인원 ÷ (스테이지에 남은 인원 + 다음으로 넘어간 인원)
        double failure_rate = (people == 0 ? 0.0 : (double)challenge[index] / (double)people);
        fail.push_back({ index, failure_rate });
    }

    // 3. 실패율이 높은 순서대로 정렬
    sort(fail.begin(), fail.end(), cmp);

    // 4. 실패율이 높은 스테이지부터 배열에 저장
    for (int index = 0; index < N; index++) answer.push_back(fail[index].first);

    return answer;
}

// 풀이 방식 :
// 1. 플레이어의 현재 진행 스테이지를 누적합으로 저장
// 2. 뒤에서부터 스테이지 별로 순회하여 실패율을 계산 및 pair 컨테이너 형태로 저장.
// 3. 저장한 스테이지별 실패율 간에 비교를 algorithm의 sort() 함수와 커스텀 비교 함수 cmp()를 통해 정렬.
// 4. 정렬된 배열을 통해 실패율로 내림차순한 스테이지의 번호를 리턴