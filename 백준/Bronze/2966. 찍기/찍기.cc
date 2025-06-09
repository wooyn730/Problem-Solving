#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ardianCnt = 0, brunoCnt = 0, goranCnt = 0;
    string ardianAns = "ABC", brunoAns = "BABC", goranAns = "CCAABB";

    int N;
    string S;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] == ardianAns[i % 3])
            ardianCnt++;
        if (S[i] == brunoAns[i % 4])
            brunoCnt++;
        if (S[i] == goranAns[i % 6])
            goranCnt++;
    }

    int maxScore = max({ ardianCnt, brunoCnt, goranCnt });

    cout << maxScore << "\n";
    if (ardianCnt == maxScore)
        cout << "Adrian\n";
    if (brunoCnt == maxScore)
        cout << "Bruno\n";
    if (goranCnt == maxScore)
        cout << "Goran\n";

    return 0;
}
