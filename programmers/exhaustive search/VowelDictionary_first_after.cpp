#include <string>

using namespace std;

int solution(string word) {
    int answer = 0;

    const string c = "AEIOU";
    const int n[5] = { 781, 156, 31, 6, 1 };

    for (int i = 0; i < word.length(); i++)
    {
        int index = c.find(word[i]);
        answer += index * n[i] + 1;
    }

    return answer;
}

// 풀이 방식 : AAAAA~AAAAU, AAAA~AAAU, AAA~AAU, AA~AU, A~U의 순서 규칙을 확인하여 코드에 대입
//             이전 코드에서 전역 변수로 사용하던 것을 지역 상수로 전환 + 기본 배열과 string으로 하여 string 컨테이너의 find() 함수 사용