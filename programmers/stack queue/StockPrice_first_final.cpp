#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    vector<int> st;

    // 배열 순회
    for (int index = 0; index < prices.size(); index++)
    {
        // 스택이 비어있지 않을 경우 while문 반복
        while (st.empty() == false)
        {
            if (prices[st.back()] <= prices[index]) break;

            // 가격이 떨어진 주식의 기간 저장
            answer[st.back()] = index - st.back();
            st.pop_back();
        }

        st.push_back(index);
    }

    // 끝까지 가격이 떨어지지 않은 주식의 기간 저장
    while (st.empty() == false)
    {
        answer[st.back()] = prices.size() - st.back() - 1;
        st.pop_back();
    }

    return answer;
}

// 풀이 방식 : 단조 스택을 사용하는 방식으로, 스택 방식의 자료구조에 인덱스를 저장하여 다음 인덱스를 넣을때마다
// 스택의 끝부분에 담긴 인덱스와 비교하며 가격이 떨어졌을 경우 주식의 기간을 계산하는 방식