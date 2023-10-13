#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for (int i=0; i<picture.size(); i++)
    {
        string a;
        for (int j=0; j<picture[i].length(); j++)
            for (int l=0; l<k; l++)
                a += picture[i][j];
        
        for (int l=0; l<k; l++)
                answer.push_back(a);
    }
    return answer;
}