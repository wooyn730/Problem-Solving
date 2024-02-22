#include <iostream>
using namespace std;

int N, M, B;
int ground[501][501];
int _min = 256, _max = 0;
int _time = -1, _height;

void DFS(int h)
{
	int _B = B;
	int _t = 0;
	int lower = 0, higher = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ground[i][j] > h)
				higher += ground[i][j] - h;
			else if (ground[i][j] < h)
				lower += h - ground[i][j];
		}
	}

	_t += higher * 2 + lower;
	_B += higher - lower;

	if (_B < 0)
		return;
	
	if (_t == _time)
	{
		if (h > _height)
			_height = h;
	}
	else if (_t < _time || _time == -1)
	{
		_time = _t;
		_height = h;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> ground[i][j];
			int t = ground[i][j];

			_min = (t < _min ? t : _min);
			_max = (t > _max ? t : _max);
		}
	}

	for (int i = _min; i <= _max; i++)
		DFS(i);

	cout << _time << " " << _height;
}