#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;

    queue<pair<int, int>> q;
    q.push({ y, 0 });

    // 방문 확인
    vector<bool> visited(y + 1, false);
    visited[y] = true;

    // BFS 알고리즘을 통해 연산
    while (q.empty() == false)
    {
        pair<int, int> p = q.front();
        q.pop();

        int count = p.second + 1;
        const int search_size = 3;
        pair<int, bool> dir[search_size] = {
            {p.first - n, true},
            {p.first / 2, p.first % 2 == 0},
            {p.first / 3, p.first % 3 == 0}
        }; // 연산 방식
        for (int i = 0; i < search_size; i++)
        {
            pair<int, bool> tmp = dir[i];

            if (tmp.second == false) continue;

            if (tmp.first == x) // y와 값이 같을 경우, 횟수 반환
            {
                return count;
            }
            else if (tmp.first > x) // y보다 값이 작을 경우, 큐에 쌓기
            {
                if (visited[tmp.first] == false) // 같은 값을 또 탐색하지 않기 위해 사용
                {
                    q.push({ tmp.first, count });
                    visited[tmp.first] = true;
                }
            }
        }
    }

    return -1;
}

// 문제 해결 : 역방향 BFS 탐색
// 특정 연산(+n, *2, *3)을 사용해 x에서 y로 변환하는 최소 횟수를 계산하는 문제
// x에서 y로 탐색할 경우 3가지 연산이 무조건 뻗어나가 불필요한 탐색을 하게됨.
// // 하지만 y에서 x로 역방향 탐색을 할 경우 유효한 역연산(-n, %2==0, %3==0)일때만 큐에 삽입하는 가지치기를 적용하여 탐색 공간을 축소함

// 트러블슈팅 및 성능 최적화
// 1. 탐색 방향 전환
// 초기 구현 시 x -> y 정방향 탐색을 시도하여 무의미한 연산이 누적되어 시간 초과가 발생함
// y -> x 역방향 탐색으로 전환하여 나누어떨어지지 않는 경우를 차단하여 무의미한 연산을 줄였음
// 
// 2. 방문 체크 자료구조 변경
// 방문 기록을 vector<int>에 넣고 find() 함수로 중복을 검사하여 탐색 오버헤드를 일으킴
// vector<bool> visited(y + 1, false)를 선언하여 인덱스로 직접 접근 하는 방식으로 중복 접근 체크 속도를 극대화함
// 
// 3. 루프 내 힙 메모리 할당 제거
// 3가지 이동 방식을 while문 내부에서 vector 컨테이너로 선언하여 매 반복마다 불필요한 힙 메모리 영역을 사용함
// 스택 메모리에 저장하는 방식인 일반 C스타일 배열로 변경하여 메모리 할당 오버헤드를 제거함. 하드코딩을 방지하기 위해 크기를 상수로 지정함

// 다른 접근 방식 : DP (다이나믹 프로그래밍)
// 크기가 y + 1인 DP 배열을 무한대로 초기화한 뒤, x부터 y까지 모든 숫자를 순회하며 최소 연산 횟수를 갱신
// DP 사용 시 코드가 매우 간결해지는 장점이 있으나, 도달할 수 없는 숫자들도 모두 순회하여 O(y-x)의 고정된 시간이 소요됨
// 반면 사용한 역방향 BFS 탐색 방식은 나누어떨어지는 유효한 경로만 선택적으로 탐색하므로 실제 실행속도가 더 빠르고, 배열의 타입(int vs bool) 차이로 인해 공간복잡도에서도 더 효율적임