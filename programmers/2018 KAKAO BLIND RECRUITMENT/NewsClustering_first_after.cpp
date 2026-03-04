#include <string>
#include <unordered_map>

using namespace std;

// 문자열을 unordered_map 컨테이너를 이용해 집합 형태로 변환하는 함수
unordered_map<string, int> toSet(string str)
{
    for (auto& c : str) c = tolower(c);

    unordered_map<string, int> _set;

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (isalpha(str[i]) && isalpha(str[i + 1]))
        {
            _set[str.substr(i, 2)]++;
        }
    }

    return _set;
}

// 집합 A,B의 합집합 원소 개수를 리턴하는 함수
int count_union(unordered_map<string, int>& set1, unordered_map<string, int>& set2)
{
    int result = 0;
    
    unordered_map<string, int> _union;
    for (const auto& pair : set1) _union[pair.first] += pair.second;
    for (const auto& pair : set2) _union[pair.first] = max(_union[pair.first], pair.second);

    for (const auto& pair : _union) result += pair.second;

    return result;
}

// 집합 A,B의 교집합 원소 개수를 리턴하는 함수
int count_intersection(unordered_map<string, int>& set1, unordered_map<string, int>& set2)
{
    int result = 0;
    
    unordered_map<string, int> _intersection;
    for (const auto& pair : set1)
    {
        if (set2.find(pair.first) != set2.end())
        {
            result += min(pair.second, set2[pair.first]);
        }
    }

    return result;
}

int solution(string str1, string str2) {
    // 두 문자열을 집합으로 만들기
    unordered_map<string, int> set1 = toSet(str1);
    unordered_map<string, int> set2 = toSet(str2);

    // 두 집합 A, B가 공집합일 경우 J(A, B) = 1로 계산
    if (set1.size() == 0 && set2.size() == 0) return 1 * 65'536;

    // 자카드 유사도 계산
    float c1 = count_intersection(set1, set2);
    float c2 = count_union(set1, set2);

    float answer = c1 / c2;

    return (int)(answer * 65'536.0f);
}