#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	
	string tmp = "";
	for (int i = 0; i < 8; i++)
	{
		tmp += A[i];
		tmp += B[i];
	}

	int T = 14;
	while (T--)
	{
		string tmp2 = "";
		for (int i = 0; i < tmp.length() - 1; i++)
		{
			int a = tmp[i] - '0';
			int b = tmp[i + 1] - '0';
			int num = (a + b) % 10;
			tmp2 += to_string(num);
		}
		tmp = tmp2;
	}

	cout << tmp;
	return 0;
}