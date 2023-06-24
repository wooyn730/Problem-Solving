#include <iostream>
using namespace std;

int main()
{
	int T = 20;
	double sum1 = 0; // 학점의 합
	double sum2 = 0; // 학점*과목평점의 합

	while (T--)
	{
		string name, score, grade;
		cin >> name >> score >> grade;
		double subAv = 0;
		switch (grade[0])
		{
		case 'A':
			subAv = 4;
			break;
		case 'B':
			subAv = 3;
			break;
		case 'C':
			subAv = 2;
			break;
		case 'D':
			subAv = 1;
			break;
		case 'F':
			subAv = 0;
			break;
		}
		if (grade.length() == 2 && grade[1] == '+')
			subAv += 0.5;

		if (grade != "P")
		{
			sum1 += score[0] - '0';
			sum2 += (score[0] - '0') * subAv;
		}
	}
	cout << (sum2 /sum1);
	return 0;
}