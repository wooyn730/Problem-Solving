#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    for (int i = 0; i < n_str.length(); i++)
        if (!(answer == "" && n_str[i] == '0'))
            answer += n_str[i];
    return answer;
}