#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> v(N); // 원본 벡터
	for (int i = 0; i < N; i++)
		cin >> v[i];

	vector<int> v2(v); // 복사본 벡터
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	// unique로 중복 값 맨 뒤로 보낸 후 중복 범위만큼 삭제

	for (int i = 0; i < N; i++)
		cout << lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() << " ";

	return 0;
}