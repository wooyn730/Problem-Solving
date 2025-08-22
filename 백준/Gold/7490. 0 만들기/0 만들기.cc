#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

void calcAndPrint(string expr) {
    int sum = 0;
    int num = 0;
    int sign = 1; // 1=+, -1=-

    for (int i = 0; i < expr.size(); ++i)
    {
        if (expr[i] == ' ')
        {
            continue; // 공백 무시
        }
        else if (expr[i] == '+')
        {
            sum += sign * num;
            num = 0;
            sign = 1;
        }
        else if (expr[i] == '-')
        {
            sum += sign * num;
            num = 0;
            sign = -1;
        }
        else
        { // 숫자
            num = num * 10 + (expr[i] - '0');
        }
    }
    sum += sign * num;

    if (sum == 0)
        cout << expr << "\n";
}

void dfs(int num, string expr)
{
    if (num == N)
    {
        expr += to_string(num);
        calcAndPrint(expr);
        return;
    }

    string nextNum = to_string(num);
    dfs(num + 1, expr + nextNum + " "); // 공백
    dfs(num + 1, expr + nextNum + "+"); // +
    dfs(num + 1, expr + nextNum + "-"); // -
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        dfs(1, "");
        cout << "\n";
    }
    return 0;
}