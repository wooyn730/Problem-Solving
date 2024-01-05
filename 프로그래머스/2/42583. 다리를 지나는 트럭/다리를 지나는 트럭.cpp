#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    for (int i=0; i<bridge_length; i++)
        bridge.push(0);
    
    int time = 0;
    int bridgeW = 0;
    for (int i=0; i<truck_weights.size(); i++)
    {
        time++;
        bridgeW -= bridge.front();
        bridge.pop();
        
        if (bridgeW + truck_weights[i] <= weight)
        {
            bridge.push(truck_weights[i]);
            bridgeW += truck_weights[i];
        }
        else
        {
            bridge.push(0);
            i--;
        }
    }
    
    while (bridgeW)
    {
        time++;
        bridgeW -= bridge.front();
        bridge.pop();
    }
    
    return time;
}