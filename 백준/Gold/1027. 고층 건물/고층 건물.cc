#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int heights[51];
int cnt[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // i빌딩에서 j빌딩이 보이는가
            bool canSee = true;
            for (int k = i + 1; k < j; k++)
            {
                // i와 j 사이에 있는 건물들 테스트
                double slope = (double)(heights[j] - heights[i]) / (j - i);
                if (heights[i] + slope * (k - i) <= heights[k])
                {
                    canSee = false;
                    break;
                }
            }
            if (canSee)
            {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    cout << *max_element(cnt, cnt + N);

    return 0;
}