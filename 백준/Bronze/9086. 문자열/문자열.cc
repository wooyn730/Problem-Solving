#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		cout << S[0] << S[S.length() - 1] << endl;
	}
	return 0;
}