#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    // 입/출차 계산
    map<string, int> in, out;
    for (int i=0; i<records.size(); i++)
    {
        int time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        string car = records[i].substr(6, 4);
        
        if (records[i][11] == 'I') // IN
            in[car] = time;
        else
        {
            out[car] += time - in[car];
            in.erase(car);
        }
    }
    
    // 출차 안된 것 계산
    for (auto car : in)
    {
        int time = 23*60 + 59;
        out[car.first] += time - in[car.first];
    }
    
    // 요금 계산
    vector<pair<string, int>> cars;
    for (auto car : out)
    {
        int fee = fees[1];
        int overtime = car.second - fees[0];
        
        if (overtime > 0)
        {
            fee += overtime / fees[2] * fees[3];
            
            if (overtime % fees[2] != 0)
                fee += fees[3];
        }
        cars.push_back({car.first, fee});
    }
    sort(cars.begin(), cars.end());
    
    // 요금 저장
    vector<int> answer;
    for (auto car : cars)
        answer.push_back(car.second);
    
    return answer;
}