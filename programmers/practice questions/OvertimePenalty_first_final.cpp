#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    // 작업량의 위치 및 한계를 가르킬 변수 선언
    int limit = *max_element(works.begin(), works.end());
    int index = limit;

    // 배열을 통해 작업량의 빈도수를 저장
    vector<int> works_count(limit + 1, 0);
    for (const auto& i : works) works_count[i]++;

    // 1. 근무 시간(n) 동안 높은 작업량부터 깎아 내리는 작업 진행
    while (n > 0 && index > 0) // 인덱스와 작업 시간(n)이 0을 가르킬 때까지 반복
    {
        if (works_count[index] == 0) // 작업량이 존재하지 않을 경우
        {
            index--;

            if (index == limit) limit--;

            continue;
        }
        else // 작업량이 존재할 경우
        {
            if (works_count[index] >= n) // 작업량이 작업시간보다 많을 경우
            {
                if (index != 1)
                    works_count[index - 1] = works_count[index - 1] + n;

                works_count[index] = works_count[index] - n;
                n = 0;

                break;
            }
            else // 작업 시간이 해당 작업량보다 많을 경우
            {
                if (index != 1)
                    works_count[index - 1] = works_count[index - 1] + works_count[index];

                n = n - works_count[index];
                works_count[index] = 0;

                if (index == limit) limit--;
            }

            index--;
        }
    }

    // 2. 야근 지수 계산. 야근 지수 = 남은 일의 작업량을 제곱하여 더한 값
    for (int index = 1; index <= limit; index++)
    {
        if (works_count[index] > 0)
        {
            long long overtime_penalty = (long long)index * index * works_count[index];
            answer = answer + overtime_penalty;
        }
    }

    return answer;
}

// 문제해결 :
// 수학적으로 계산해보았을 때, 가장 높은 숫자를 먼저 깎아내려야 남은 작업량의 제곱의 합이 최소가 됨을 파악함.
// 또한 작업량이 중복될 수 있다는 점에 착안하여, 매번 최댓값을 찾는 대신 작업량의 빈도수를 체크하여 높은 작업량을 일괄적으로 깎아내리는 방식을 고안 및 적용함

// 정석풀이와의 비교 및 효율성 : 
// 학습 과정에서 이 문제의 보편적인 정석 접근법은 우선순위 큐(Max Heap)를 사용해 최댓값을 찾아 1씩 깎고 다시 넣는 방식임을 알게 됨
// 그러나 큐의 삽입/삭제 오버헤드가 발생하지 않아 실행 속도 측면에서 더 뛰어나다는 것을 확인하여 내 코드의 효율성이 좋다는 것을 깨닿게 됨

// 트러블슈팅 및 코드 리팩토링
// 1. 자료 구조 최적화 : 초기에 빈도수 저장을 위해 unordered_map을 사용했으나 불필요한 해시 연산 과정이 존재하기에 일반 vector 배열로 수정하여 속도 최적화
// 2. 오버플로우 방지 : 최종 야근 지수를 더할때 (long long)(index * index * works_count[index])로 캐스팅하였는데, 이미 오버플로우 된 값을 캐스팅하도록 하여 계산 전 미리 캐스팅하는 방식으로 수정