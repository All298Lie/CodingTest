#include <string>
#include <algorithm> // reverse() 함수 사용

using namespace std;

// 진법에 맞게 숫자 세주는 함수
string ntos(int number, int n)
{
    if (number == 0) return "0";

    const string num = "0123456789ABCDEF";
    string tmp = "";

    while (number > 0)
    {
        tmp += num[number % n];
        number /= n;
    }

    reverse(tmp.begin(), tmp.end());

    return tmp;
}

string solution(int n, int t, int m, int p) { // n : 진법, t : 숫자 갯수, m : 참여 인원, p : 내 순서
    string answer = "";
    int num = 0;

    p = p - 1; // 인덱스 기준으로 계산하기 위해 조정
    int size = m * t; // 내가 받을 문자열 크기

    // 문자열에 문자 추가
    string tmp = "";
    while (tmp.length() < size) tmp += ntos(num++, n);

    for (int index = p; (index < tmp.length() && answer.size() < t); index += m)
    {
        answer.push_back(tmp[index]);
    }

    return answer;
}

// 문제 해결 :
// 문제의 제한 사항을 고려하여, 무거운 문자열 덧셈 대신 CPU 처리 속도가 가장 빠른 정수 연산(/, %)을 활용해 진법 변환 함수 구현.
// 참가 인원과 구할 개수를 곱해 내가 확인해야 할 전체 문자열의 길이를 미리 구하여 이어 붙임.
// 전체 문자열에서 내 순서부터 시작하도록 하며 인원수 만큼 인덱스를 점프하여 정답만 빠르게 추출.
