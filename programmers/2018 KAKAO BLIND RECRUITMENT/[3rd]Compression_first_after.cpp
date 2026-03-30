#include <string>
#include <string_view> // string 대신 사용할 컨테이너.
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string_view, int> dic;
    string_view alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 알파벳 저장
    for (int index = 0; index < alphabet.size(); index++) // 알파벳 A-Z를 dic에 저장
    {
        dic[string_view(alphabet).substr(index, 1)] = dic.size() + 1;
    }

    int index = 0;
    while (index < msg.size()) // 인덱스가 msg 끝까지 올때까지 반복
    {
        int length = 0;
        bool isExist = true;

        string_view view;
        string_view before;

        do // do - while문으로 인덱스부터 길이까지의 위치에 있는 글자가 dic에 있는지 확인
        {
            length = length + 1;

            if (index + length - 1 >= msg.size())
            {
                before = view;
                break;
            }

            if (view.empty() == false) before = view;
            view = string_view(msg).substr(index, length);

            if (dic[view] == 0) // dic[view]가 존재하지 않을 경우 값이 0으로 생성됨
            {
                dic[view] = dic.size();
                isExist = false;
            }
        } while (isExist == true); // find() 함수를 통해 dic에서 찾을 때, it이 끝을 가르킬 때까지 반복 

        // 찾은 단어 위치 출력 및 존재하지 않는 단어 추가
        answer.push_back(dic[before]);

        index = index + length - 1; // 인덱스 위치 조정
    }

    return answer;
}

// 문제 해결 :
// before 방식에서 단어 탐색에 쓰이는 배열을 vector에서 map으로 변경

// 트러블 슈팅 :
// dic[view] == 0으로 확인을 할때 C++에서는 존재하지 않는 경우, 추가하고 초기 값을 0으로 지정함. 
// before 코드처럼 do-while문을 빠져나온 뒤 dic.size() + 1로 값을 설정할 경우,
// 이미 추가된 단어 때문에 1의 오차범위가 생겨나게 되는 것을 디버깅을 통해 확인하여 수정함.


