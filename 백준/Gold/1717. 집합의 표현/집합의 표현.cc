#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    while (m--)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 0) // 합침
        {
            unionSet(a, b);
        }
        else // 확인
        {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
