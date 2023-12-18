#include <string>
#include <vector>
#include <string> //substr
#include <map> //map

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> term; // term[약관 종류]=유효기간
    // 오늘 날짜
    int Y1 = stoi(today.substr(0, 4));
    int M1 = stoi(today.substr(5, 7));
    int D1 = stoi(today.substr(8, 10));
    
    for (int i=0; i<terms.size(); i++)
        term.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].length()))));
    
    for (int i=0; i<privacies.size(); i++)
    {
        // 약관 시작 날짜
        int Y2 = stoi(privacies[i].substr(0, 4));
        int M2 = stoi(privacies[i].substr(5, 7));
        int D2 = stoi(privacies[i].substr(8, 10));

        // 약관 마감 날짜
        int month = term[privacies[i][11]];
        while (month--)
        {
            D2 += 28;
            if (month==0)
                D2--; // 마감 마지막날 제외
            
            if (D2 > 28)
            {
                D2 -= 28;
                M2++;
            }
            if (M2 > 12)
            {
                M2 -= 12;
                Y2++;
            }
        }
        
        // 판별
        if (Y1>Y2 || Y1==Y2 && M1>M2 || Y1==Y2 && M1==M2 && D1>D2)
            answer.push_back(i+1);
    }
    return answer;
}