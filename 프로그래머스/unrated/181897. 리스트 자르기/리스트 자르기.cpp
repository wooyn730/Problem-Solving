#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int a = (n == 1 ? 0 : slicer[0]);
    int b = (n != 2 ? slicer[1] : num_list.size()-1);
    int c = (n == 4 ? slicer[2] : 1);
    for (int i=a; i<=b; i+=c)
    {
        answer.push_back(num_list[i]);
    }
    return answer;
}