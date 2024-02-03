#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> network[201];
bool visit[201];
int answer;

void BFS(int i)
{
    answer++;
    
    queue<int> q;
    q.push(i);
    visit[i] = true;
    while (!q.empty())
    {
        int com = q.front();
        q.pop();
        
        for (int i=0; i<network[com].size(); i++)
        {
            int next = network[com][i];
            if (!visit[next])
            {
                q.push(next);
                visit[next] = true;
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
            BFS(i);
    
    return answer;
}
