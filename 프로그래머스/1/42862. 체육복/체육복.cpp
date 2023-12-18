#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // ����
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) // �����л� == �����л� ����
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

    for (int i = 0; i < lost.size(); i++) // �յ� �л� �����ֱ�
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