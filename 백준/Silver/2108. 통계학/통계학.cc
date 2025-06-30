#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int nums[500001];
int cnt[8001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];

        sum += nums[i];
        cnt[nums[i] + 4000]++;
    }

    sort(nums, nums + N);

    int avg = round(sum / N);
    int mid = nums[N / 2];

    int mx = 0, idx1 = -1, idx2 = -1;
    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            idx1 = i;
            idx2 = -1;
        }
        else if (cnt[i] == mx && idx2 == -1)
        {
            idx2 = i;
        }
    }

    int frequent = (idx2 == -1 ? idx1 : idx2) - 4000;
    int range = nums[N - 1] - nums[0];
    cout << avg << "\n" << mid << "\n" << frequent << "\n" << range;

    return 0;
}
