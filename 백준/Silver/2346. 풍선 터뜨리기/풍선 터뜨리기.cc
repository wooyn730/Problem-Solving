#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<pair<int, int>> deq; // 풍선 번호, 안에 있는 숫자

void PopBalloon(int idx)
{
	if (idx > 0)
	{
		idx--;
		while (idx != 0)
		{
			// 가장 왼쪽 풍선을 가장 오른쪽으로 보냄
			deq.push_back(deq.front());
			deq.pop_front();

			idx--;
		}
	}
	else if (idx < 0)
	{
		while (idx != 0)
		{
			// 가장 오른쪽 풍선을 가장 왼쪼긍로
			deq.push_front(deq.back());
			deq.pop_back();

			idx++;
		}
	}

	cout << deq.front().first << " ";
	int n = deq.front().second;
	deq.pop_front();

	if (!deq.empty())
		PopBalloon(n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		deq.push_back(make_pair(i, num));
	}

	PopBalloon(0);

	return 0;
}