#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;

bool CheckGoodSequence(string str)
{
	int len = str.length();

	for (int i = 1; i <= len / 2; i++)
	{
		string substr1 = str.substr(len - i * 2, i);
		string substr2 = str.substr(len - i, i);

		if (substr1 == substr2)
			return false;
	}

	return true;
}

void BackTraking(int cnt, string str)
{
	if (!CheckGoodSequence(str))
		return;

	if (cnt == N)
	{
		cout << str;
		exit(0);
	}

	BackTraking(cnt + 1, str + '1');
	BackTraking(cnt + 1, str + '2');
	BackTraking(cnt + 1, str + '3');
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	BackTraking(0, "");
}