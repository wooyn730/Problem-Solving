#include <iostream>
#include <deque>
using namespace std;

deque<int> rotation;
int ans;

void GetLessRotation(int num)
{
	int cnt1 = 0, cnt2 = 0;
	deque<int> left = rotation;
	deque<int> right = rotation;

	while (left.front() != num)
	{
		left.push_back(left.front());
		left.pop_front();
		cnt1++;
	}
	while (right.front() != num)
	{
		right.push_front(right.back());
		right.pop_back();
		cnt2++;
	}

	if (cnt1 <= cnt2)
	{
		rotation = left;
		ans += cnt1;
	}
	else
	{
		rotation = right;
		ans += cnt2;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, num;
	cin >> N >> M;
		
	for (int i = 1; i <= N; i++)
		rotation.push_back(i);

	while (M--)
	{
		cin >> num;

		if (rotation.front() != num)
			GetLessRotation(num);
		
		rotation.pop_front();
	}

	cout << ans;
}