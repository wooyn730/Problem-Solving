#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    queue<bool> signs;
    queue<int> nums;
    int num = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '+')
        {
            signs.push(true);
            nums.push(num);
            num = 0;
        }
        else if (S[i] == '-')
        {
            signs.push(false);
            nums.push(num);
            num = 0;
        }
        else
        {
            num = num * 10 + S[i] - '0';
        }

        if (i == S.length() - 1)
        {
            nums.push(num);
            num = 0;
        }
    }

    int sum = 0;
    bool isMinusAppear = false;
    while (true)
    {
        if (nums.empty())
            break;

        if (!isMinusAppear)
        {
            sum += nums.front();
        }
        else
        {
            sum -= nums.front();
        }
        nums.pop();

        if (signs.empty())
            break;

        if (!signs.front())
            isMinusAppear = true;
        signs.pop();
    }

    cout << sum;
    return 0;
}
