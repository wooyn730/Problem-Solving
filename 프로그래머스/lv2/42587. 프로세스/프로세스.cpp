#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int>a, pair<int, int> b)
{
    return a.first > b.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> priority;
    queue<pair<char, int>> process;
    char myP = 'A'+location;
    
    for (int i=0; i<priorities.size(); i++)
    {
        // 프로세스 이름과 우선순위 저장 ex.('A', 2)
        process.push(make_pair('A'+i, priorities[i])); 
        
        // 우선순위 숫자 종류와 개수 저장 ex.(2, 2)
        bool exist = false;
        for (int j=0; j<priority.size(); j++)
        {
            if (priorities[i] == priority[j].first)
            {
                exist = true;
                priority[j].second++;
            }
        }
        if (!exist)
            priority.push_back(make_pair(priorities[i], 1));
    }
    
    // 우선순위 종류 내림차순으로 정렬
    sort(priority.begin(), priority.end(), compare);
    
    /*
    for (int j=0; j<priority.size(); j++)
        cout << priority[j].first << " " << priority[j].second << endl;
    
    
    while (!process.empty())
    {
        //cout << process.front().first << " " << process.front().second <<endl;
        process.pop();
    }*/
        
    // 큐의 front 가장 높은 우선순위라면 pop, 아니라면 pop 후 다시 push
    // pop할 때 answer+1을 해주고, 내가 찾던 프로세스라면 끝내고 리턴
    while (!process.empty())
    {
        int tmp = process.front().second;
        if (tmp == priority[0].first)
        {
            // 프로세스 처리
            answer++;
            
            if (process.front().first == myP) // 종료
                return answer;

            process.pop();
            
            
            // 우선순위 처리
            priority[0].second--;
            if (priority[0].second == 0)
                priority.erase(priority.begin(), priority.begin()+1);
            
            
        }
        else
        {
            process.push(process.front());
            process.pop();
        }
        
    //    if (tmp == priority[0].first)
    //        process.pop();
    }
    
    return answer;
}