#include <string>
#include <set>
#include <map>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> set1;
    map<string, int> set2;
    int _intersection = 0, _union = 0;
    
    for (int i=0; i<str1.length()-1; i++)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1]))
            continue;
        
        str1[i] = tolower(str1[i]);
        str1[i+1] = tolower(str1[i+1]);
        
        string a = str1.substr(i, 2);
        _union++;
        
        if (set1.find(a) != set1.end())
            set1[a]++;
        else
            set1.insert({a, 1});
    }
    
    for (int i=0; i<str2.length()-1; i++)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))
            continue;
        
        str2[i] = tolower(str2[i]);
        str2[i+1] = tolower(str2[i+1]);
        
        string a = str2.substr(i, 2);
        _union++;
        
        if (set2.find(a) != set2.end())
            set2[a]++;
        else
            set2.insert({a, 1});
    }
    
    for (auto iter : set2)
    {
        if (set1.find(iter.first) == set1.end())
        {
            set1.insert({iter.first, iter.second});
        }
        else
        {
            int a = iter.second;
            int b = set1.find(iter.first)->second;
            _intersection += (a < b ? a : b);
        }
    }
    
    float ans = 65536;
    
    if (!set1.empty())
    {
        _union -= _intersection;
        ans = ans * _intersection / _union;
    }
    
    return ans;
}