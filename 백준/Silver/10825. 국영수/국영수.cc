#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
	string name;
	int kor;
	int eng;
	int math;
};

bool compare(Student a, Student b)
{
	if (a.kor != b.kor)
		return a.kor > b.kor;
	else if (a.eng != b.eng)
		return a.eng < b.eng;
	else if (a.math != b.math)
		return a.math > b.math;
	else
		return a.name < b.name;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<Student> std;
	
	while (N--)
	{
		Student s1;
		cin >> s1.name >> s1.kor >> s1.eng >> s1.math;

		std.push_back(s1);
	}

	sort(std.begin(), std.end(), compare);

	for (int i = 0; i < std.size(); i++)
		cout << std[i].name << "\n";
}