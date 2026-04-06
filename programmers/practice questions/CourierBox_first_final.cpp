#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    vector<int> tmp; // 보조 컨테이너
    int index = 0; // order 포인터
    int number = 1; // 다음 택배 상자 번호
    while (index < order.size())
    {
        if (number <= order.size() && number == order[index]) // 현재 화물이 다음 순번일 경우
        {
            number = number + 1;
            index = index + 1;

            answer = answer + 1;
        }
        else if (tmp.empty() == false && tmp.back() == order[index]) // 가장 최근 보조 컨테이너 벨트의 화물이 다음 순번일 경우
        {
            index = index + 1;
            tmp.pop_back();

            answer = answer + 1;
        }
        else if (number <= order.size()) // 두 컨테이너 벨트에서 트럭으로 화물을 못 옮길 경우, 보조 컨테이너 벨트로 화물 이동
        {
            tmp.push_back(number);
            number = number + 1;
        }
        else
        {
            break;
        }
    }

    return answer;
}

// 문제해결 :
// 보조 컨테이너 벨트는 입구가 하나이며 가장 마지막에 보관한 상자부터 꺼내는 방식
// 해당 방식은 LIFO 구조로, 스택 자료구조를 활용하여 서브 컨테이너를 구현하여 문제를 해결함