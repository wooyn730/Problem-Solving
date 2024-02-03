#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> network[201];
bool visit[201];
int answer;

void DFS(int i)
{
    answer++;
    
    stack<int> s;
    s.push(i);
    visit[i] = true;
    while (!s.empty())
    {
        int com = s.top();
        s.pop();
        
        for (int i=0; i<network[com].size(); i++)
        {
            int next = network[com][i];
            if (!visit[next])
            {
                s.push(com);
                s.push(next);
                visit[next] = true;
                break;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    for (int i=0; i<computers.size(); i++)
    {
        for (int j=0; j<n-1; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (computers[i][j] == 1 && computers[i][k] == 1)
                {
                    network[j].push_back(k);
                    network[k].push_back(j);
                }
            }
        }
    }
    
    for (int i=0; i<n; i++)
        if (!visit[i])
            DFS(i);
    
    return answer;
}
