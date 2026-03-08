#include <string>
#include <vector>

using namespace std;

vector<string> a = { "aya", "ye", "woo", "ma" };

// 재귀함수를 통해 단어를 계속 탐색
int change(const string& str, const string& before, int index)
{
    // 인덱스가 문자열 뒤를 가르키고 있을 경우 통과
    if (index == str.size()) return 1;

    for (const string& word : a)
    {
        if (index + word.length() > str.length()) continue;

        if (str.compare(index, word.length(), word) == 0) {
            if (word == before) return 0;

            return change(str, word, index + word.length());
        }
    }

    return 0;
}

// 문제
int solution(vector<string> babbling)
{
    int answer = 0;

    for (auto& str : babbling) answer += change(str, "", 0);

    return answer;
}

// 풀이 방식 : for문으로 단어를 순회하며, compare() 함수를 통해 단어를 비교
//             단어가 적은 단순 문제라 for문을 사용해 순회하는 방식 사용.
//             단어가 많아질 경우, unordered_set 컨테이너를 사용해 기존에 쓰던 substr()함수와 find()함수가 효율적