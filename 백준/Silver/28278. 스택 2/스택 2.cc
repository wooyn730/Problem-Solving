#include <iostream>
using namespace std;

int num[1000000], top = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, k;
	cin >> N;

	while (N--)
	{
		cin >> k;
		switch (k)
		{
		case 1:
			int x;
			cin >> x;
			num[top++] = x;
			break;
		case 2:
			if (top != 0)
			{
				cout << num[top-1] << "\n";
				top--;
			}
			else
				cout << -1 << "\n";
			break;
		case 3:
			cout << top << "\n";
			break;
		case 4:
			if (top == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
			break;
		case 5:
			if (top != 0)
			{
				cout << num[top-1] << "\n";
			}
			else
				cout << -1 << "\n";
			break;
		}
	}
	return 0;
}