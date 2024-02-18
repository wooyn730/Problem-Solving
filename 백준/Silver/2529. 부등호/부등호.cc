#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
bool sign[10];

vector<long long> vec;
bool visit[10];
long long biggest = 0, smallest = 9999999999;
string bigStr, smallStr;

void DFS(int cnt)
{
	if (cnt == k + 1)
	{
		bool isRight = true;
		for (int i = 0; i < k; i++)
		{
			if (!(sign[i] && vec[i] > vec[i + 1])
				&& !(!sign[i] && vec[i] < vec[i + 1]))
			{
				isRight = false;
				break;
			}
		}

		if (isRight)
		{
			long long num = 0;
			string ans = "";
			for (int i = 0; i < vec.size(); i++)
			{
				num = num * 10 + vec[i];
				ans += to_string(vec[i]);
			}

			if (num > biggest)
			{
				biggest = num;
				bigStr = ans;
			}
			if (num < smallest)
			{
				smallest = num;
				smallStr = ans;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		vec.push_back(i);
		DFS(cnt + 1);
		visit[i] = false;
		vec.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		char c;
		cin >> c;
		
		sign[i] = (c == '>');
	}

	DFS(0);

	cout << bigStr << "\n" << smallStr;
}