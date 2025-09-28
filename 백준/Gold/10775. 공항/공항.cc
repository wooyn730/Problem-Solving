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
    parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int G, P; // gate, plane
    cin >> G >> P;

    parent.resize(G + 1);
    for (int i = 1; i <= G; i++)
        parent[i] = i;

    int ans = 0;
    for (int i = 0; i < P; i++)
    {
        int g;
        cin >> g;

        int gate = find(g);
        if (gate == 0) break;
        ans++;

        unionSet(gate, gate - 1);
    }
    cout << ans;
}
