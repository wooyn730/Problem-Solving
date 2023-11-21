#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, setPrice = -1, eachPrice = -1;
	cin >> N >> M;

	while (M--)
	{
		int s, e;
		cin >> s >> e;

		if (setPrice == -1)
			setPrice = s;
		else if (s < setPrice)
			setPrice = s;

		if (eachPrice == -1)
			eachPrice = e;
		else if (e < eachPrice)
			eachPrice = e;
	}

	if (eachPrice * 6 <= setPrice)
		cout << eachPrice * N;
	else if (eachPrice * (N % 6) <= setPrice)
		cout << setPrice * (N / 6) + eachPrice * (N % 6);
	else
		cout << setPrice * (N / 6) + (N / 6 == 0 ? 0 : setPrice);
}