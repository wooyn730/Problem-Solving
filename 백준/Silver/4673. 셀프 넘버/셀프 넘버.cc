#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int selfnum[10001] = { 0 }, n;

    for (int i = 1; i <= 10000; i++)
    {
        int n = i, sum = i;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }

        if (sum <= 10000)
            selfnum[sum]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (selfnum[i] == 0)
            cout << i << '\n';
    }
}