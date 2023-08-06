#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = -100000;
    for (int i=idx; i<arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            answer = i;
            break;
        }
    }
    return (answer == -100000 ? -1 : answer);
}