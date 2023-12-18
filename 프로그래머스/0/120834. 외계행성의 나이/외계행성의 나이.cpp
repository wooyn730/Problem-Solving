#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    while (age)
    {
        char ch = age%10 + 'a';
        answer = ch + answer;
        age /= 10;
    }
    return answer;
}