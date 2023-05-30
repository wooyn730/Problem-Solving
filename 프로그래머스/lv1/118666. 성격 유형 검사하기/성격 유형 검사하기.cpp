#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<vector<int>>types(2,vector <int>(4,0));
    int isRev = 0; // 1이면 뒤집
    int type = 0; 
    
    for (int i=0; i<survey.size(); i++)
    {
        if (survey[i] == "RT" || survey[i] == "TR")
        {
            type = 0;
            isRev = (survey[i] == "RT" ? 0 : 1);
        }
        else if (survey[i] == "CF" || survey[i] == "FC")
        {
            type = 1;
            isRev = (survey[i] == "CF" ? 0 : 1);
        }
        else if (survey[i] == "JM" || survey[i] == "MJ")
        {
            type = 2;
            isRev = (survey[i] == "JM" ? 0 : 1);
        }
        else if (survey[i] == "AN" || survey[i] == "NA")
        {
            type = 3;
            isRev = (survey[i] == "AN" ? 0 : 1);
        }
        
        if (choices[i] < 4)
            types[isRev][type] += 4-choices[i];
        else
            types[(isRev == 1 ? 0 : 1)][type] += choices[i]-4;
    }
    
    answer += (types[0][0] >= types[1][0] ? "R" : "T");
    answer += (types[0][1] >= types[1][1] ? "C" : "F");
    answer += (types[0][2] >= types[1][2] ? "J" : "M");
    answer += (types[0][3] >= types[1][3] ? "A" : "N");
    return answer;
}