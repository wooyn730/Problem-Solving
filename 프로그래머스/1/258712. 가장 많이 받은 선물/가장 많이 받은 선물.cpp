#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // 친구들이 있다
    // 선물 줬으면 +1, 받았으면 -1로 선물 지수를 각각 매긴다
    // 첫 친구부터 다른 친구들과의 선물 주고받기 관계를 체크한다.
    
    // 주는 이와 받는 이 pair로 저장
    vector<pair<string, string>> gt; // give and take
    for (int i=0; i<gifts.size(); i++)
    {
        for (int j=0; j<gifts[i].size(); j++)
        {
            if (gifts[i][j] == ' ')
            {
                gt.push_back({gifts[i].substr(0, j), gifts[i].substr(j+1, gifts[i].length() - j - 1)});
                //cout << gt[gt.size()-1].first << " " << gt[gt.size()-1].second << "\n";
            }
        }
    }
    
    // 선물지수 계산
    vector<int> gn(friends.size()); // gift number
    for (int i=0; i<friends.size(); i++)
    {
        for (int j=0; j<gt.size(); j++)
        {
            if (friends[i] == gt[j].first)
                gn[i]++;
            else if (friends[i] == gt[j].second)
                gn[i]--;
        }
        //cout << i << " " << gn[i] << "\n";
    }
    
    // 누가 누구에게 줄 지
    vector<int> nmg(friends.size()); // next month gift
    for (int i=0; i<friends.size() - 1; i++)
    {
        for (int j=i+1; j<friends.size(); j++)
        {
            int iGet = 0;
            int jGet = 0;
            for (int k=0; k<gt.size(); k++)
            {
                if (friends[i] == gt[k].first && friends[j] == gt[k].second)
                    jGet++;
                else if (friends[j] == gt[k].first && friends[i] == gt[k].second)
                    iGet++;
            }
            if (iGet > jGet)
                nmg[j]++;
            else if (jGet > iGet)
                nmg[i]++;
            else
            {
                if (gn[i] > gn[j])
                    nmg[i]++;
                else if (gn[j] > gn[i])
                    nmg[j]++;
            }
        }
    }
    return *max_element(nmg.begin(), nmg.end());;
}