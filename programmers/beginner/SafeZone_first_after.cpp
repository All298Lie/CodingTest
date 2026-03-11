#include <string>
#include <vector>

using namespace std;

bool minesweeper(const vector<vector<int>>& board, int row, int col)
{
    for (int dir_row = -1; dir_row <= 1; dir_row++)
    {
        for (int dir_col = -1; dir_col <= 1; dir_col++)
        {
            int next_row = dir_row + row;
            int next_col = dir_col + col;

            if (next_row < 0 || next_row >= board.size()) continue;
            if (next_col < 0 || next_col >= board[0].size()) continue;

            if (board[next_row][next_col] == 1)
            {
                return false;
            }
        }
    }
    
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            answer += minesweeper(board, row, col);
        }
    }

    return answer;
}

// 문제 해결 : 다중 for문을 사용해서 배열을 탐색.
// 폭탄은 3x3 범위를 가지고 있으므로, 안전 구역 또한 주변 3x3 범위를 확인하면 안전한지 확인 가능.
// 배운점 :
// 1. 배열 탐색은 재귀 방식이 어울리지 않음.
// 2. 함수로 값을 호출할 때, 컨테이너의 경우 주소 참조를, 일반 자료형은 값 복사를 하는 것이 좋음.