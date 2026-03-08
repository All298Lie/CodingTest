#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> c = { 'A', 'E', 'I', 'O', 'U' };
vector<int> n = { 781, 156, 31, 6, 1 };

int solution(string word) {
    int answer = 0;

    for (int i = 0; i < word.length(); i++)
    {
        int index = find(c.begin(), c.end(), word[i]) - c.begin();
        answer += index * n[i] + 1;
    }

    return answer;
}

// 풀이 방식 :
// AAAAA~AAAAU, AAAA~AAAU, AAA~AAU, AA~AU, A~U의 순서 규칙을 확인하여 switch문을 활용하여 작성하였으나,
// switch문과 문자열 길이 비교를 자주 써, 코드를 리펙토링하여 압축
// 문제점 :
// 전역 변수 대신 지역 변수로, 값이 변하지 않으니 상수로 선언,
// vector<char> 사용대신 string과 string의 find() 함수를 사용하면 코드가 더 깔끔해짐

// 기존에 시도하려한 코드 :

/*
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    switch(word[0])
    {
        case 'U': answer += 781;
        case 'O': answer += 781;
        case 'I': answer += 781;
        case 'E': answer += 781;
        case 'A': answer += 1;
        default: break;
    }
    if (word.length() < 2) return answer;
    
    switch(word[1])
    {
        case 'U': answer += 156;
        case 'O': answer += 156;
        case 'I': answer += 156;
        case 'E': answer += 156;
        case 'A': answer += 1;
        default: break;
    }
    if (word.length() < 3) return answer;
    
    switch(word[2])
    {
        case 'U': answer += 31;
        case 'O': answer += 31;
        case 'I': answer += 31;
        case 'E': answer += 31;
        case 'A': answer += 1;
        default: break;
    }
    if (word.length() < 4) return answer;
    
    switch(word[3])
    {
        case 'U': answer += 6;
        case 'O': answer += 6;
        case 'I': answer += 6;
        case 'E': answer += 6;
        case 'A': answer += 1;
        default: break;
    }
    if (word.length() < 5) return answer;
    
    switch(word[4])
    {
        case 'U': answer += 1;
        case 'O': answer += 1;
        case 'I': answer += 1;
        case 'E': answer += 1;
        case 'A': answer += 1;
        default: break;
    }
    return answer;
}
*/