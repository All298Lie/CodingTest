#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 일부 케이스에서 런타임 에러로 인한 실패
int solution(int n, int k)
{
    int answer = 0;

    // 1. n을 k진수로 변경
    string number = "";
    if (k == 10)
    {
        number = to_string(n);
    }
    else
    {
        while (n != 0)
        {
            number = to_string(n % k) + number;
            n /= k;
        }
    }

    // 2. k진수로 변경한 수에서 P0, 0P0, 0P에서 P 추출하기
    vector<pair<int, int>> P;
    string tmp = ""; // 임시 변수
    for (const auto& c : number)
    {
        if (c == '0')
        {
            if (tmp.empty() == true) continue;

            int val = stoi(tmp);

            auto it = find_if(P.begin(), P.end(), [val](pair<int, int> a) {return a.first == val; });
            if (it != P.end())
            {
                (it->second)++;
            }
            else
            {
                P.push_back({ val, 1 });
            }

            tmp.clear();
        }
        else
        {
            tmp += c;
        }
    }

    if (tmp.empty() == false)
    {
        int val = stoi(tmp);

        auto it = find_if(P.begin(), P.end(), [val](pair<int, int> a) {return a.first == val; });

        if (it != P.end())
        {
            (it->second)++;
        }
        else
        {
            P.push_back({ val, 1 });
        }
    }

    int max = max_element(P.begin(), P.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; })->first;

    // 4. 에라토스테네스의 체를 사용해 max 값까지의 소수 판별
    vector<bool> isPrime(max + 1, true);
    isPrime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * 2; j <= max; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // 5. P값이 소수일 경우 P 갯수만큼 answer 증가
    for (const auto& _pair : P)
    {
        if (isPrime[_pair.first] == true) answer += _pair.second;
    }

    return answer;
}

// 풀이 방식 : 에라토스테네스의 체는 100만 이하의 숫자 중 소수를 전부 찾을때 최강의 효율을 보이지만,
// 이 문제 처럼 개수는 얼마 없는데 숫자 하나하나의 덩치가 클 경우 메모리 낭비가 심함
// 해당 방식은 최악의 경우 숫자의 크기가 어마무시하게 커지기 때문에 int로는 담을 수 없음.
// stoll() 함수를 통해 문자를 long long 자료형으로 받고 받은 수마다 소수인지 판단하여 카운트