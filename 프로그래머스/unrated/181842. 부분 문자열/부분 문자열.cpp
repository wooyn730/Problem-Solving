#include <string>
using namespace std;

int solution(string str1, string str2) {
    for (int i=0; i<=str2.length()-str1.length(); i++)
        if (str1 == str2.substr(i, str1.length()))
            return 1;
    return 0;
}