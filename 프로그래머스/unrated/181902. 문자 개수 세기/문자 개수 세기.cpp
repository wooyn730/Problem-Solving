#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for (int i=0; i<my_string.length(); i++)
    {
        if (my_string[i]>='a')
            answer[my_string[i]-'a'+26]++;
        else
            answer[my_string[i]-'A']++;
    }
    return answer;
}