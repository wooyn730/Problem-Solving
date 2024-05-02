#include <string>
#include <vector>
using namespace std;

bool num[100000];

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for (int i=0; i<arr.size(); i++)
    {
        if (!num[arr[i]])
        {
            num[arr[i]] = true;
            answer.push_back(arr[i]);
        }
        if (answer.size() >= k)
            break;
    }
    for (int i=answer.size(); i<k; i++)
        answer.push_back(-1);
    return answer;
}