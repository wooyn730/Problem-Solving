#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second == b.second) // 같은 실패율
        return a.first < b.first; // 이름 오름차순
    else
        return a.second > b.second; // 실패율 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failureRate;

    for (int i = 1; i <= N; i++) // 도달, 진행 저장
    {
        double reachNum = 0; // 도달한 인원
        double doingNum = 0; // 진행중 인원
        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] >= i)
                reachNum++;
            if (stages[j] == i)
                doingNum++;
        }

        if (reachNum == 0) // 0 나누기 방지
            reachNum = 1;
        failureRate.push_back(make_pair(i, (doingNum / reachNum)));
    }

    sort(failureRate.begin(), failureRate.end(), compare);

    for (int i = 0; i < N; i++)
        answer.push_back(failureRate[i].first);
    return answer;
}