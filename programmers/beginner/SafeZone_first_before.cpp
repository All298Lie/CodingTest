#include <string>
#include <vector>

using namespace std;

// 재귀 함수를 통해 처음부터 마지막까지 확인
int minesweeper(vector<vector<int>>& board, const int& x, const int& y)
{
    if (x == board.front().size())
    {
        if (y == board.size())
        {
            int empty = 0;

            for (const auto& line : board)
                for (const auto& p : line)
                    if (p == 0) empty++;

            return empty;
        }

        // 해당 행을 다 확인했다면 다음 열로 이동
        return minesweeper(board, 0, y + 1);
    }

    if (board[x][y] == 1)
    {
        for (int a = y - 1; a < y + 2; a++)
        {
            for (int b = x - 1; b < x + 2; b++)
            {
                if (a < 0 || a >= board.size()) continue;
                if (b < 0 || b >= board.front().size()) continue;

                if (board[b][a] == 0) board[b][a] = 2;
            }
        }
    }

    // 다음 행으로 이동하여 확인
    return minesweeper(board, x + 1, y);
}

int solution(vector<vector<int>> board)
{
    return minesweeper(board, 0, 0);
}

// 문제 해결 : 재귀 함수 방식으로 모든 행렬을 확인 및 폭탄이 발견될 경우, 주변 8곳의 값을 변경. 
// 마지막에 값이 0인 모든 부분의 값 더해서 리턴
// 문제점 : 재귀의 깊이때문에 공간복잡도와 효율성이 좋지 않음.
// 이런 문제(배열 탐색)의 해결방식은 재귀 함수가 아닌 방향 배열을 이용하여 다중 for문을 통해 좌표를 확인하는 것이 정석