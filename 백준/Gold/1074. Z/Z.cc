#include <iostream>
using namespace std;

int N, r, c, ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 1사분면
        Z(y, x, size / 2);
        // 2사분면
        Z(y, x + size / 2, size / 2);
        // 3사분면
        Z(y + size / 2, x, size / 2);
        // 4사분면
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
        ans += size * size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    Z(0, 0, (1 << N));
}