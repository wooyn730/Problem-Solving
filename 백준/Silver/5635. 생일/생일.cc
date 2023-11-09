#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int day;
	int month;
	int year;
};

bool compare(Student a, Student b)
{
	if (a.year != b.year)
		return a.year > b.year;
	else if (a.month != b.month)
		return a.month > b.month;
	else
		return a.day > b.day;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<Student> std;
	
	while (n--)
	{
		Student s1;
		cin >> s1.name >> s1.day >> s1.month >> s1.year;
		std.push_back(s1);
	}

	sort(std.begin(), std.end(), compare);

	cout << std[0].name << "\n" << std[std.size() - 1].name;
}