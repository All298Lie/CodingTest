#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> a = { "aya", "ye", "woo", "ma" };

// 재귀 함수를 통해 단어를 계속 탐색
string change(string str, string before)
{
    if (str.length() == 0) return "A";
    else if (str.length() == 1) return "B";

    auto it = find(a.begin(), a.end(), str.substr(0, 2));
    if (it != a.end())
    {
        if (*it == before) return "B";

        return change(str.substr(2), *it);
    }

    it = find(a.begin(), a.end(), str.substr(0, 3));
    if (str.length() > 2 && it != a.end())
    {
        if (*it == before) return "B";

        return change(str.substr(3), *it);
    }

    return "B";
}

// 문제
int solution(vector<string> babbling)
{
    int answer = 0;

    for (string str : babbling)
    {
        if (change(str, "") == "A") answer++;
    }

    return answer;
}

// 풀이 방식 : find()함수와 substr()을 통해 문자열을 끊어서 일치하는 단어가 있는지 확인
// 문제점 : substr()과 재귀 함수 실행과정에서 불필요한 메모리 복사가 됨