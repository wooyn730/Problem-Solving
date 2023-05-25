#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    for (int i=0; i<strings.size(); i++)
    {
        for (int j=i; j>0; j--)
        {
            if (strings[j-1][n] > strings[j][n])
            {
                string tmp = strings[j-1];
                strings[j-1] = strings[j];
                strings[j] = tmp;
            }
            else if (strings[j-1][n] == strings[j][n])
            {
                if (strings[j-1] > strings[j])
                {
                    string tmp = strings[j-1];
                    strings[j-1] = strings[j];
                    strings[j] = tmp;
                }
            }
        }
    }
    
    return strings;
}