#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    pair<int, int> ABvec = { xb - xa, yb - ya };
    pair<int, int> BCvec = { xc - xb, yc - yb };
    pair<int, int> ACvec = { xc - xa, yc - ya };

    int crossProject = ABvec.first * BCvec.second - ABvec.second * BCvec.first;
    if (crossProject == 0)
    {
        cout << -1;
        return 0;
    }

    double lineAB = sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
    double lineBC = sqrt(pow((xb - xc), 2) + pow((yb - yc), 2));
    double lineAC = sqrt(pow((xa - xc), 2) + pow((ya - yc), 2));

    double circum[3] = { 0 };
    circum[0] = (lineAB + lineBC) * 2;
    circum[1] = (lineBC + lineAC) * 2;
    circum[2] = (lineAC + lineAB) * 2;

    sort(circum, circum + 3);
    double diff = circum[2] - circum[0];
    cout << fixed << setprecision(10) << diff;

    return 0;
}