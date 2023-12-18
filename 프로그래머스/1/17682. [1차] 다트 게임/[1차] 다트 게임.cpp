#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    vector<int> score;

    for (int i = 0; i < dartResult.length(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (dartResult[i] == '1' && dartResult[i + 1] == '0')
            {
                score.push_back(10);
                i++;
            }
            else
                score.push_back(dartResult[i] - '0');
        }
        else
        {
            switch (dartResult[i])
            {
            case 'S':
                score[score.size() - 1] *= 1; // ÀÇ¹Ì x?
                break;
            case 'D':
                score[score.size() - 1] *= score[score.size() - 1];
                break;
            case 'T':
                score[score.size() - 1] *= score[score.size() - 1] * score[score.size() - 1];
                break;
            case '*':
                score[score.size() - 1] *= 2;
                if (score.size() >= 2)
                    score[score.size() - 2] *= 2;
                break;
            case '#':
                score[score.size() - 1] *= -1;
                break;
            }
        }
    }
    return score[0] + score[1] + score[2];
}