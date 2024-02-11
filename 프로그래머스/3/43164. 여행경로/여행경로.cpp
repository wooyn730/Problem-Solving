#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> _tickets;
bool visit[10001];
vector<string> answer;

bool DFS(string cur, int usedTickets)
{
    answer.push_back(cur);
    
    if (usedTickets == _tickets.size())
        return true;
    
    for (int i=0; i<_tickets.size(); i++)
    {
        if (_tickets[i][0] == cur && !visit[i])
        {
            visit[i] = true;
            
            if (DFS(_tickets[i][1], usedTickets+1))
                return true;
            
            visit[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());
    _tickets = tickets;
    
    DFS("ICN", 0);
    
    return answer;
}