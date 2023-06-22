#include <iostream>
#include <string>
using namespace std;

int main() {
	string S[101];
	int i = 0;

	while (getline(cin, S[i]))
		cout << S[i++] << endl;
	return 0;
}