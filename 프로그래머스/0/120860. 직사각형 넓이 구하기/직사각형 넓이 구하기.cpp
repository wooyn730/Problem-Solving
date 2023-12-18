#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int x1 = 256, x2 = 256, y1 = 256, y2 = 256;
    for (int i=0; i<dots.size(); i++)
    {
        if (x1 == 256)
            x1 = dots[i][0];
        else if (x1 != dots[i][0])
            x2 = dots[i][0];
        if (y1 == 256)
            y1 = dots[i][1];
        else if (y1 != dots[i][1])
            y2 = dots[i][1];
    }
    return ((x1 > x2 ? x1 - x2 : x2 - x1) * (y1 > y2 ? y1 - y2 : y2 - y1));
}