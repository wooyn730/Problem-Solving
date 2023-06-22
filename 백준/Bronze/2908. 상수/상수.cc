#include <iostream>
using namespace std;

int main() {
	int A, B, a, b;
	cin >> A >> B;
	a = (A % 10 * 100) + (A % 100 - A % 10) + (A / 100);
	b = (B % 10 * 100) + (B % 100 - B % 10) + (B / 100);
	cout << (a > b ? a : b);
	return 0;
}