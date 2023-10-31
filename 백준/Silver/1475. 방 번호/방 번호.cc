#include <iostream>
using namespace std;

int num[10];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	int set = 0;
	cin >> N;

	for (int i = 0; i < N.length(); i++)
	{
		num[N[i] - '0']++;
	}
	
	int six_nine = (num[6] + num[9] + ((num[6]+num[9])%2==0 ? 0 : 1)) / 2;
	num[6] = six_nine;
	num[9] = six_nine;

	for (int i = 0; i <= 9; i++)
	{
		if (num[i] > set)
			set = num[i];
	}

	cout << set;
}