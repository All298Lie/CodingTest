#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    vector<int> st;

    for (int index = 0; index < numbers.size(); index++)
    {
        while (!st.empty())
        {
            if (numbers[index] <= numbers[st.back()]) break;

            answer[st.back()] = numbers[index];
            st.pop_back();
        }
        st.push_back(index);
    }

    return answer;
}

// 풀이 방식 : 단조 스택 기법을 사용하여, 시간 복잡도를 최적화.
// 배열의 값 자체가 아닌 인덱스를 스택에 저장하여, 아직 짝을 찾지 못한 원소들을 대기시키고, 조건을 만족하는
// 새 원소가 등장할 때 한 번에 연쇄적으로 정산하는 매커니즘 적용

// 단조 스택 : 데이터를 넣고 뺄 때 스택 내부의 원소들이 항상 오름차순이나 내림차순 정렬 상태를 유지하도록
// 강제하는 기법.

// 단조 스택을 떠올려야하는 사용처
// 1. 가장 가까운 큰/작은 값 탐색할 경우
// 2. O(N^2) 탐색의 한계가 보일 경우
// 3. 순서와 거리를 추적할 경우