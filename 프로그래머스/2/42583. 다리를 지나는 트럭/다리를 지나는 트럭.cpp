#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    for (int i=0; i<bridge_length; i++)
        bridge.push(0);
    
    int time = 0;
    int truck = 0;
    int bridgeW = 0;
    while (truck < truck_weights.size() || bridgeW)
    {
        time++;
        bridgeW -= bridge.front();
        bridge.pop();
        
        if (truck < truck_weights.size() && bridgeW + truck_weights[truck] <= weight)
        {
            bridge.push(truck_weights[truck]);
            bridgeW += truck_weights[truck];
            truck++;
        }
        else
            bridge.push(0);
    }
    
    return time;
}
