#include <string>

using namespace std;

// 진법에 맞게 숫자 세주는 함수
string counting(int n, string number)
{
    string result = number;

    int index = result.length() - 1;
    int upper = 1;

    while (upper > 0)
    {
        int tmp;
        if (result[index] >= 'A' && result[index] <= 'F') // 값이 10 이상일 경우
        {
            tmp = result[index] - 'A' + 10;
        }
        else // 값이 10 미만일 경우
        {
            tmp = result[index] - '0';
        }

        tmp = tmp + upper; // 값 upper만큼 증가
        upper = 0;

        if (tmp >= n) // 값이 진법에 의해 다음 단위로 넘어가는 경우
        {
            result[index] = tmp - n + '0';

            if (index == 0) // 다음 인덱스가 존재하지 않을 경우
            {
                result = "1" + result;
            }
            else // 다음 인덱스가 존재할 경우
            {
                index = index - 1;
                upper = 1;
            }
        }
        else // 값이 진법보다 낮을 경우
        {
            if (tmp >= 10)
            {
                result[index] = tmp - 10 + 'A';
            }
            else
            {
                result[index] = tmp + '0';
            }
        }
    }

    return result;
}

string solution(int n, int t, int m, int p) { // n : 진법, t : 숫자 갯수, m : 참여 인원, p : 내 순서
    string answer = "";
    string next = "0";

    int index = 0;
    int turn = 1;

    if (p == m) p = 0;

    // 숫자의 개수만큼 answer의 길이가 될 경우 빠져나오는 반복문
    while (answer.length() < t)
    {
        if (next.length() > index) // 출력할 숫자가 남아있을 경우
        {
            if (turn % m == p) // 내 턴일 경우
            {
                answer.push_back(next[index]);
            }

            turn = turn + 1;
            index = index + 1;
        }
        else // 출력한 숫자가 안남아 있을 경우 진법에 맞게 숫자 카운팅
        {
            next = counting(n, next);

            index = 0;
        }
    }

    return answer;
}

// 문제 해결 :
// 숫자를 1씩 증가시키며 문자열로 변환하고, 턴을 카운팅하여 내 순서일때 문자를 추출하는 방식 사용.
// 현재 문자열의 인덱스 탐색이 끝나면, 다음 숫자를 새로운 string으로 변환해 인덱스를 0번부터 재시작 하도록 구성

// 트러블슈팅 :
// 1. 문자-숫자 아스키코드(ANCII) 맵핑 오류 해결 :
// - 초기 구현 시 정수 값과 문자 '0'의 아스키 코드 값을 혼동하여 비정상적인 문자가 연산되는 이슈 발생
// - 문자에 '0'이나 'A'를 더하거나 빼는 명시적 오프셋 계산 방식으로 수정하여 직관성과 정확성 확보
// 2. C++ string 객체의 메모리 재할당 오버헤드 최적화
// - C++에서 string 결합 시 s = s + "a" 방식을 사용할 경우 매번 새로운 임시 객체가 동적 할당되고 문자열 전체 복사가 발생해 심각한 메모리 낭비가 발생함을 확인.
// - 기존 메모리 공간을 재활용하기 위해 제자리 수정이 가능한 += (복합 대입 연산자) 및 push_back() 함수를 사용하여 속도 최적화.
// - C# 환경에서는 string이 불변 객체이므로 + =  연산자 역시 가비지를 생성함. 따라서 타 언어에서는 메모리 최적화를 위해 StringBuilder 클래스를 사용해야 한다는 아키텍처적 차이를 함께 학습
