#include <string>
using namespace std;

int solution(string A, string B) {
    int T = A.length();
    while (T-- > 1)
    {
        string a = A.substr(T, A.length()-T)+A.substr(0, T);
        if (a == B)
            return A.length()-T;
    }
    return (A==B ? 0 : -1);
}