#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	set<int> numbers;

	while (N--)
	{
		int num;
		cin >> num;
		numbers.insert(num);
	}

	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
		cout << *iter << " ";
}