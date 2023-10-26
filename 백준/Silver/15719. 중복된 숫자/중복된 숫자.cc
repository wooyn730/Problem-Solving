#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    int N;
    cin >> N;
    
    bool check[10000000] = { 0 }; // 등장한 숫자 1 아닌 숫자 0
    int M;

    while(N--)
    {
        cin >> M;

        if (check[M] == 0)
            check[M] = 1;
        else
            break;
    }

    cout << M;
    return 0;
}