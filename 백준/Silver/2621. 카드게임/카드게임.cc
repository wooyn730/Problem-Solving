#include <iostream>
using namespace std;

bool isSameColor = true;
char c;
int nums[10];

bool isConsecutive(int bigNum)
{
	if (bigNum < 5)
		return false;

	for (int i = bigNum; i > bigNum - 5; i--)
		if (!nums[i])
			return false;

	return true;
}

int findCardCnt(int cnt, int startIdx = 0)
{
	for (int i = startIdx + 1; i <= 9; i++)
		if (nums[i] == cnt)
			return i;
	
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int biggest = 0, ans;

	for (int i = 0; i < 5; i++)
	{
		char t;
		cin >> t;

		if (isSameColor)
		{
			if (i == 0)
				c = t;
			else if (c != t)
				isSameColor = false;
		}
		
		int n;
		cin >> n;
		nums[n]++;

		if (n > biggest)
			biggest = n;
	}

	if (isSameColor && isConsecutive(biggest))
		ans = biggest + 900;
	else if (findCardCnt(4))
		ans = findCardCnt(4) + 800;
	else if (findCardCnt(3) && findCardCnt(2))
		ans = findCardCnt(3) * 10 + findCardCnt(2) + 700;
	else if (isSameColor)
		ans = biggest + 600;
	else if (isConsecutive(biggest))
		ans = biggest + 500;
	else if (findCardCnt(3))
		ans = findCardCnt(3) + 400;
	else if (findCardCnt(2) && findCardCnt(2, findCardCnt(2)))
		ans = findCardCnt(2, findCardCnt(2)) * 10 + findCardCnt(2) + 300;
	else if (findCardCnt(2))
		ans = findCardCnt(2) + 200;
	else
		ans = biggest + 100;
	
	cout << ans;
}