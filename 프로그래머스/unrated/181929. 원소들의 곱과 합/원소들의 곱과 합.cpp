#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int mul = 1;
    int sum = 0;
    for (int i=0; i<num_list.size(); i++)
    {
        mul *= num_list[i];
        sum += num_list[i];
    }
    
    if (mul < sum*sum)
        return 1;
    else
        return 0;
}