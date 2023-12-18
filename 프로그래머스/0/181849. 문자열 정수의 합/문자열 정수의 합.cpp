#include <string>
using namespace std;

int solution(string num_str) {
    int answer = 0;
    for (char a : num_str)
        answer += a-'0';
    return answer;
}