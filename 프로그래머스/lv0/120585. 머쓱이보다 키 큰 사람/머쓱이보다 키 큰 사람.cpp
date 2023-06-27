#include <vector>
using namespace std;

int solution(vector<int> array, int height) {
    int bigger = 0;
    for (int i=0; i<array.size(); i++)
        if (height < array[i])
            bigger++;
    return bigger;
}