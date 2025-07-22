#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int nums[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N > 0)
    {
        nums[N % 10]++;
        N /= 10;
    }

    int sum69 = nums[6] + nums[9];
    nums[6] = sum69 / 2;
    nums[9] = sum69 / 2 + (sum69 % 2 == 0 ? 0 : 1);

    cout << *max_element(nums, nums + 10);
    return 0;
}