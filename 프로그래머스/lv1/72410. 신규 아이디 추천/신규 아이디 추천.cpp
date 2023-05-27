#include <string>
#include <vector>
#include <cctype> // isupper 사용

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    
    for (int i=0; i<new_id.length(); i++)
    {
        // 대문자 => 소문자 (1)
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
        
        // 소문자 숫자 - _ .만 가능 (2)
        if (islower(new_id[i]) || (new_id[i]-'0'>=0 && new_id[i]-'0'<=9) || new_id[i] == 45 || new_id[i] == 46 || new_id[i] == 95 )
            answer += new_id[i];
    }
    
    // 마침표 연속 불가 (3)
    for (int j=0; j<answer.length(); j++)
    {
        if (j!=0 && answer[j]==46 && answer[j-1]==46)
            continue;
        tmp += answer[j];
    }
    answer = tmp;
    
    if (answer[0] == 46) // 마침표 첫자리 불가 (4)
    {
        tmp = "";
        for (int j=1; j<answer.length(); j++)
        {
            tmp += answer[j];
        }
        answer = tmp;
    }
        
    if (answer == "") // 빈 문자열이면 a (5)
    {
        answer = "a";
    }
    
    if (answer.length() > 15) // 최대 15자 (6-1)
    {
        tmp = "";
        for (int j=0; j<15; j++)
            tmp += answer[j];
        answer = tmp;
    }
    
    while (answer[answer.length()-1] == 46) // 제거 후 마지막이 마침표면 제거 (6-2)
    {
        tmp = "";
        for (int j=0; j<answer.length()-1; j++)
        {
            tmp += answer[j];
        }
        answer = tmp;
    }
    
    while (answer.length() < 3) // 길이가 2자 이하면 마지막 문자 반복 (7)
        answer += answer[answer.length()-1];
        
    return answer;
}