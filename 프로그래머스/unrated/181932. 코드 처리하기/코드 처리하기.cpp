#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    int mode = 0;
    string ret = "";
    for (int i=0; i<code.length(); i++)
    {
        if (mode == 0)
        {
            if (code[i] == '1')
                mode = 1;
            else
            {
                if (i%2==0)
                    ret += code[i];
            }
        }
        else
        {
            if (code[i] == '1')
                mode = 0;
            else
            {
                if (i%2!=0)
                    ret += code[i];
            }
        }
    }
    if (ret == "")
        ret = "EMPTY";
    return ret;
}