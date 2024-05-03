#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> applicant;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		applicant.clear();

		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			applicant.push_back({a, b});
		}

		sort(applicant.begin(), applicant.end());

		int ans = 1;
		int worstInterview = applicant[0].second;

		for (int i = 1; i < N; i++)
		{
			if (applicant[i].second < worstInterview)
			{
				worstInterview = applicant[i].second;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}