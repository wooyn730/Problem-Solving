#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int wantCnt = 0;
    vector<int> get;
    for (int i=0; i<number.size(); i++)
        wantCnt += number[i];
    
    for (int i=0; i<=discount.size()-want.size(); i++)
    {
        vector<int> get(want.size());
        for (int j=i; j<wantCnt+i; j++)
            for (int k=0; k<want.size(); k++)
                if (discount[j]==want[k])
                    get[k]++;
        int cnt=0;
        for (int l=0; l<get.size(); l++)
            if (get[l] == number[l])
                cnt++;
        if (cnt == get.size())
            answer++;
    }
    return answer;
}