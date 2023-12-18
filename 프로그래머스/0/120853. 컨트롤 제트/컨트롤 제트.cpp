#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    vector<string> word;
    int a = 0;
    s += " ";
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==' ')
        {
            string k = s.substr(a, i-a);
            word.push_back(k);
            a = i+1;
        }
    }
    
    int answer = 0;
    for (int i=word.size()-1; i>=0; i--)
    {
        if (word[i]=="Z")
            i--;
        else
            answer += stoi(word[i]);
    }
    return answer;
}