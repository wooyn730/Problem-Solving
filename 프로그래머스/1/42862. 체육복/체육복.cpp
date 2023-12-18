#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) // 도난학생 == 여벌학생 제거
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                j--;
            }
        }
    }
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++) // 앞뒤 학생 빌려주기
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j] + 1 || lost[i] == reserve[j] - 1)
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                answer++;
                i--;
                j--;
                break;
            }
        }
    }
    return answer;
}