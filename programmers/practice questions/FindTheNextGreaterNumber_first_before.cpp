#include <vector>

using namespace std;

// 일부 케이스에서 타임아웃이 발생하여 문제 해결 실패
vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);

    for (int point = 0; point < numbers.size() - 1; point++)
    {
        for (int index = point + 1; index < numbers.size(); index++)
        {
            if (numbers[point] < numbers[index])
            {
                answer[point] = numbers[index];
                break;
            }
        }
    }

    return answer;

}

// 풀이 방식 : 현재 인덱스부터 마지막 인덱스까지 현재 인덱스 값보다 큰 값을 찾음
// 문제점 : 이중 for문 방식을 사용하여 최악의 경우 시간복잡도가 O(N^2)가 되버림
// 이 문제를 해결하기 위해선 단조 스택 기법을 사용해야함.