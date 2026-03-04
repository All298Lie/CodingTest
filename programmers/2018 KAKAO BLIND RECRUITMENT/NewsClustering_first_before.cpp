#include <string>
#include <vector>
#include <set> // set 컨테이너, multiset 컨테이너 사용

using namespace std;

// 문자열을 vector 컨테이너를 이용해 집합 형태로 변환하는 함수
vector<string> toSet(string str)
{
    for (auto& c : str) c = tolower(c);

    multiset<string> mts;

    for (int i = 1; i < str.length(); i++)
    {
        if (!(isalpha(str[i - 1]) && isalpha(str[i]))) continue;

        mts.insert(str.substr(i - 1, 2));
    }

    return vector<string>(mts.begin(), mts.end());
}

// 집합 A,B의 합집합 원소 개수를 리턴하는 함수
int count_union(vector<string> set1, vector<string> set2)
{
    int result = 0;
    multiset<string> mts1(set1.begin(), set1.end());
    multiset<string> mts2(set2.begin(), set2.end());

    multiset<string> _union(mts1.begin(), mts1.end());
    for (auto str : mts2) _union.insert(str);

    set<string> _un(_union.begin(), _union.end());

    for (auto str : _un)
    {
        result += max(mts1.count(str), mts2.count(str));
    }

    return result;
}

// 집합 A,B의 교집합 원소 개수를 리턴하는 함수
int count_intersection(vector<string> set1, vector<string> set2)
{
    int result = 0;
    multiset<string> mts1(set1.begin(), set1.end());
    multiset<string> mts2(set2.begin(), set2.end());

    multiset<string> _intersection(mts1.begin(), mts1.end());
    for (auto str : mts2) _intersection.insert(str);

    set<string> _is(_intersection.begin(), _intersection.end());

    for (auto str : _is)
    {
        if (_intersection.count(str) < 2) continue;
        if (min(mts1.count(str), mts2.count(str)) < 1) continue;

        result += min(mts1.count(str), mts2.count(str));
    }

    return result;
}

int solution(string str1, string str2) {
    // 두 문자열을 집합으로 만들기
    vector<string> set1 = toSet(str1);
    vector<string> set2 = toSet(str2);

    // 두 집합 A, B가 공집합일 경우 J(A, B) = 1로 계산
    if (set1.size() == 0 && set2.size() == 0) return 1 * 65536;

    // 자카드 유사도 계산
    float c1 = count_intersection(set1, set2);
    float c2 = count_union(set1, set2);

    float answer = c1 / c2;

    return (int)(answer * 65536.0f);
}