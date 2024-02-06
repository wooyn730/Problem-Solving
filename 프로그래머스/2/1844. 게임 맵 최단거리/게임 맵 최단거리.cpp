#include<vector>
#include<queue>
using namespace std;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

typedef struct {
	int x, y, cnt;
}pos;

bool visit[101][101];
int ans = -1;

int solution(vector<vector<int>> maps)
{
    queue<pos> q;
    q.push({0, 0, 1});
    visit[0][0] = true;
    
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        
        if (x == maps.size() - 1 && y == maps[0].size() - 1)
            ans = (ans == -1 ? cnt : (ans < cnt ? ans : cnt));
        
        for (int i=0; i<4; i++)
        {
            int _x = x + nx[i];
            int _y = y + ny[i];
            
            if (_x >= 0 && _x < maps.size() && _y >= 0 && _y < maps[0].size())
            {
                if (maps[_x][_y] == 1 && !visit[_x][_y])
                {
                    q.push({_x, _y, cnt+1});
                    visit[_x][_y] = true;
                }
            }
        }
    }
    
    return ans;
}