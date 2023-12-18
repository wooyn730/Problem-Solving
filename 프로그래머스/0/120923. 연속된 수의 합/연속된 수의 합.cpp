#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer(num);
    int start = total/num - num/2;
    if (num%2==0)
        start++;
    
    for (int i=0; i<num; i++)
        answer[i] = start++;
    
    return answer;
}