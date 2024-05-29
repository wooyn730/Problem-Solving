#include <string>
using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    for (int i=0; i<cipher.length(); i++)
        if (i%code == code - 1)
            answer = answer + cipher[i];
    return answer;
}