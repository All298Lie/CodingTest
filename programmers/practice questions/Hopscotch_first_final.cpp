#include <vector>

using namespace std;

// 동적 프로그래밍
int DP(vector<vector<int>>& land)
{
    for (int row = 0; row < land.size(); row++)
    {
        int first = -1;
        int first_col = -1;

        int second = -1;

        for (int col = 0; col < land[row].size(); col++)
        {
            if (first < land[row][col])
            {
                second = first;
                first = land[row][col];
                first_col = col;
            }
            else if (second < land[row][col])
            {
                second = land[row][col];
            }
        }

        if (row == land.size() - 1) return first;

        for (int col = 0; col < land[row + 1].size(); col++)
        {
            if (col == first_col) land[row + 1][col] = land[row + 1][col] + second;
            else land[row + 1][col] = land[row + 1][col] + first;
        }
    }
}

int solution(vector<vector<int>> land)
{
    return DP(land);
}

// 초기 접근 : 모든 경로의 경우의 수를 구하기 위해 DFS/BFS 탐색을 시도함.
// 하지만 행의 개수가 100,000까지 올 수있다보니 시간초과가 뜨게됨.
// 최선과 차선을 구하고 다음 행에서 최선과 더했을 때 가장 큰 값을 구할 수 있도록 구하면 될거같다는 생각을 함.
// 하지만 진전이 없다가 동적 프로그래밍 방식을 사용하면 된다는 힌트를 얻음.

// 문제 해결 : 동적 프로그래밍 방식을 사용하여 현재 행에서 최선과 차선의 값을 구하고,
// 최선의 열에는 차선의 값을, 그 외에는 최선의 값을 다음 행에 더하는 방식을 사용해 마지막에 가장 큰 값을 리턴하도록 함