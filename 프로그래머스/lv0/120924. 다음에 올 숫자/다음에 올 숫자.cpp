#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int s = common.size();
    if (common[s-1] - common[s-2] == (common[s-2] - common[s-3]))
        return common[s-1] * 2 - common[s-2];
    else
        return common[s-1] * common[s-1] / common[s-2];
}