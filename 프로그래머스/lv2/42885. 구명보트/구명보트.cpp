#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque <int> p;
    
    for (int i=0; i<people.size(); i++)
        p.push_back(people[i]);

    sort(p.rbegin(), p.rend());
    
    while (!p.empty())
    {
        if (p.size() != 1 && p.front() + p.back() <= limit) // 가벼운 사람 탈 수 있으면 낑겨타기
        {
            p.pop_back();
        }
        p.pop_front();
        answer++;
    }
    
    return answer;
}