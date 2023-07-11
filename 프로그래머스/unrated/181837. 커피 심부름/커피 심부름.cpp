#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for (int i=0; i<order.size(); i++)
    {
        bool isLatte = false;
        for (int j=0; j<order[i].length(); j++)
        {
            if (order[i][j]=='l')
            {
                isLatte = true;
                break;
            }
        }
        answer += (isLatte ? 5000 : 4500);
    }
    return answer;
}