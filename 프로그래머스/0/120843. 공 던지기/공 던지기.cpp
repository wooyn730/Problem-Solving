#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    while (k > 1)
    {
        answer += 2;
        if (answer > numbers.size() - 1)
            answer -= numbers.size();
        k--;
    }
    return numbers[answer];
}