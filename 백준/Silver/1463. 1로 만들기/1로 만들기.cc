#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    nums[1] = 0;

    for (int i = 2; i <= N; i++) {
        nums[i] = nums[i - 1] + 1;

        if (i % 2 == 0)
            nums[i] = min(nums[i], nums[i / 2] + 1);
        if (i % 3 == 0)
            nums[i] = min(nums[i], nums[i / 3] + 1);
    }

    cout << nums[N];
    return 0;
    
}