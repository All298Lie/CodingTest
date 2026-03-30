#include <string>
#include <string_view> // string 대신 사용할 컨테이너.
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    vector<string_view> dic(1, string_view("+"));
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 알파벳 저장
    for (int index = 0; index < alphabet.size(); index++) // 알파벳 A-Z를 dic에 저장
    {
        dic.push_back(string_view(alphabet).substr(index, 1));
    }

    int index = 0;
    while (index < msg.size()) // 인덱스가 msg 끝까지 올때까지 반복
    {
        int length = 0;
        int tmp = 0;

        string_view view;
        auto it = dic.end();

        do // do - while문으로 인덱스부터 길이까지의 위치에 있는 글자가 dic에 있는지 확인
        {
            length = length + 1;

            if (index + length - 1 >= msg.size())
            {
                tmp = it - dic.begin();
                break;
            }

            view = string_view(msg).substr(index, length);

            if (it != dic.end()) tmp = it - dic.begin();
            it = find(dic.begin(), dic.end(), view);
        } while (it != dic.end()); // find() 함수를 통해 dic에서 찾을 때, it이 끝을 가르킬 때까지 반복 

        // 찾은 단어 위치 출력 및 존재하지 않는 단어 추가
        dic.push_back(view);
        answer.push_back(tmp);

        index = index + length - 1; // 인덱스 위치 조정
    }

    return answer;
}

// 문제 해결 :
// vector<string_view> 컨테이너에 초기 알파벳을 넣고 문자열을 탐색할때 존재할 경우 다음 문자까지 더하여 탐색하도록 설정
// 만약에 다음 문자까지 더했을 때 단어가 배열에 존재하지 않을 경우 이전 단어 번호를 출력하고, 존재하지 않는 단어를 배열에 추가 하는 방식 사용
// string_view를 통해 string이 복제되어 메모리 용량을 추가적으로 사용하지 않도록 함.
// string_view : 포인터 개념으로 원본에서 시작 지점, 길이를 기억하여 사용하는 자료구조.

// 피드백 :
// vector 컨테이너를 사용하여 문자를 탐색할 때마다 O(V)의 순차 탐색이 발생하여 시간 복잡도가 최적화 되어있지 않음.
// -> map 컨테이너를 사용하면 내부적 트리 구조를 통해 O(log V)만에 탐색이 가능하므로 시간 복잡도를 극적으로 줄일 수 있음.
// (단, V는 사전(dir)의 크기)