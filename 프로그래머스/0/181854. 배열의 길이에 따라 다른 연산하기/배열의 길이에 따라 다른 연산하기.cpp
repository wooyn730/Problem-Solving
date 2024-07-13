#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer = arr;
    
    for (int i=0; i<arr.size(); i++)
    {
        if ((i%2==0 && arr.size()%2==1) || (i%2==1 && arr.size()%2==0))
            answer[i] += n;
    }
    
    return answer;
}