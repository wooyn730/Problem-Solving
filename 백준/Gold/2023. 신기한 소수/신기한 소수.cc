#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void AmazingPrimeNum(int len, int num)
{
    if (len == N)
    {
        cout << num << "\n";
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        int newNum = num * 10 + i;
        if (isPrime(newNum))
            AmazingPrimeNum(len + 1, newNum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    AmazingPrimeNum(1, 2);
    AmazingPrimeNum(1, 3);
    AmazingPrimeNum(1, 5);
    AmazingPrimeNum(1, 7);

    return 0;
}
