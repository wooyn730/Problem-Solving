#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string A, B, C = "";
	cin >> A >> B;

	vector<int> vA(A.length()), vB(B.length());
	int iA = 0, iB = 0;
	for (int i = A.length() - 1; i >= 0; i--)
		vA[iA++] = A[i] - '0';
	for (int i = B.length() - 1; i >= 0; i--)
		vB[iB++] = B[i] - '0';

	int bigger = A.length() > B.length() ? A.length() : B.length();
	int carry = 0;
	for (int i = 0; i < bigger + 1; i++)
	{
		int num = carry;
		if (i < A.length())
			num += vA[i];
		if (i < B.length())
			num += vB[i];

		if (num >= 10)
		{
			num %= 10;
			carry = 1;
		}
		else
			carry = 0;

		if (!(num ==0 && i == bigger))
			C = to_string(num) + C;
	}
	cout << C;
	return 0;
}