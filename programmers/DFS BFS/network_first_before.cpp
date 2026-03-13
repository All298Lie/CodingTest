#include <vector>

using namespace std;

int Find(vector<int>& network, int com)
{
    if (network[com] == com) return com;

    network[com] = Find(network, network[com]);
    return network[com];
}

void Union(vector<int>& network, int a, int b)
{
    int fa = Find(network, a);
    int fb = Find(network, b);

    if (fa != fb)
    {
        if (network[fa] < network[fb]) network[fb] = fa;
        else network[fa] = fb;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    // 1. 네트워크 생성 및 설정
    vector<int> network(n, 0);
    for (int i = 0; i < n; i++) network[i] = i;

    // 2. 유니온-파인드 알고리즘을 사용하여 네트워크 연결을 이어줌
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i) continue;
            if (computers[i][j] == 1) Union(network, i, j);
        }
    }

    //(트러블슈팅) 3. 네트워크 본래 번호를 가지고 있는 컴퓨터 확인 후 카운트
    for (int i = 0; i < n; i++)
        if (network[i] == i) answer++;

    return answer;
}

// 문제 해결 : 2학년 2학기때 배운 유니온-파인드 알고리즘을 통해 연결된 네트워크를 확인
// 트러블슈팅 : 몇 개의 네트워크가 존재하는지 확인하는 과정에서 set 컨테이너를 사용하여 확인하려 했음
// 해당 방식의 문제점으로 자식 노드(본인 네트워크 번호를 가지지 않은 컴퓨터)를 호출하지 않으면 과거 부모 노드를 가리키는 문제 발생
// -> for문으로 본인 번호를 가지고 있는 컴퓨터 개수를 셀 경우 네트워크 수를 알 수 있으므로, for문 사용

// 배운점 : 해당 문제는 깊이 우선 탐색(DFS)와 유니온-파인드(Union-Find) 알고리즘 둘 중 하나만 알아도 풀 수 있는 문제였음.
// 하지만 문제 조건이 달라진다면 DFS가 유리하거나, Union-Find가 유리해질 수 있음.
//  예를 들면, DFS의 경우 항상 처음부터 계산을 시작하여 재귀를 해야하지만,
// 실시간으로 네트워크가 계속 추가적으로 연결되거나, 반복적으로 연결되어있는지 확인한다면 Union-Find가 유리.
//  반대로 연결된 경로를 알아야 하거나, 거쳐갈 수 있는 네트워크가 한정되어있을 경우,
// 거쳐간 컴퓨터를 일일이 확인 가능한 DFS는 사용 가능하나, 순서 상관 없이 묶어버리며, 정보의 관리가 어려워 사용할 수 없음. 