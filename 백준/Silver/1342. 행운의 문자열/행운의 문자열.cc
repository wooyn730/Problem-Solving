#include <iostream>
#include <algorithm>
using namespace std;

string S;
int L;
bool visited[10];
long long answer = 0;

void GetLuckyNum(int size, char lastChar)
{
    if (size == L)
    {
        answer++;
        return;
    }

    for (int i = 0; i < L; i++)
    {
        if (visited[i]) continue;
        if (i > 0 && S[i] == S[i - 1] && !visited[i - 1]) continue;
        if (size > 0 && lastChar == S[i]) continue;

        visited[i] = true;
        GetLuckyNum(size + 1, S[i]);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    L = S.length();

    sort(S.begin(), S.end());
    GetLuckyNum(0, '\0');

    cout << answer;
    return 0;
}
