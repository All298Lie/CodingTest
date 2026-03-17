#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

// 소수인지 판별하는 함수
bool isPrime(long long number)
{
    if (number < 2) return false;

    for (long long ll = 2; ll <= sqrt(number); ll++)
    {
        if (number % ll == 0) return false;
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    // 1. n을 k진수로 변경
    string str = "";
    if (k == 10)
    {
        str = to_string(n);
    }
    else
    {
        while (n != 0)
        {
            str = to_string(n % k) + str;
            n /= k;
        }
    }

    // 2. k진수로 변경한 수에서 P0, 0P0, 0P에서 P 추출하여 소수인지 판별
    stringstream ss(str);
    string tmp = ""; // 임시 변수
    while (getline(ss, tmp, '0'))
    {
        if (tmp.empty() == true) continue;

        long long number = stoll(tmp);

        if (isPrime(number) == true) answer++;
    }

    return answer;
}

// 풀이 방식 : 숫자 n을 K진수로 변경.
// 변경한 수를 getline() 함수를 통해 '0'으로 나눠져있는 숫자를 구하여 소수인지 판별 후 카운트

// 트러블슈팅 :
// - 자료형 한계 극복 : K진수로 변환된 숫자가 int의 범위를 초과할 수 있으므로, stoll()을 사용하여 long long으로 처리
// - 소수 판별 최적화 : 에라토스테네스의 체를 사용하여 1조 단위의 배열을 만들면 메모리 초과가 발생함.
//   따라서 숫자를 하나씩 추출할 때마다 개별 소수 판별 함수를 호출하도록 최적화