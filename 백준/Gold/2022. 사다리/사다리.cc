#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

double x, y, c;

double GetC(double w)
{
    double h1 = sqrt(pow(x, 2) - pow(w, 2));
    double h2 = sqrt(pow(y, 2) - pow(w, 2));
    return h1 * h2 / (h1 + h2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> c;

    double low = 0, high = min(x, y);

    while (high - low > 0.00001)
    {
        double mid = (low + high) / 2;
        if (GetC(mid) < c)
            high = mid;
        else
            low = mid;
    }

    cout << low;
    return 0;
}