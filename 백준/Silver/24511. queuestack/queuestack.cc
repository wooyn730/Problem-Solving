#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque <int> queuestack;
int state[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A, B, M, C;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> state[i];
		// 스택은 영향 x
		// 큐는 합쳐서 하나의 deque로 만듦
	}

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (state[i] == 0)
			queuestack.push_back(x);
	}

	cin >> M;
	while (M--)
	{
		int num;
		cin >> num;

		queuestack.push_front(num);
		cout << queuestack.back() << " ";
		queuestack.pop_back();
	}

	return 0;
}