#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> student1 = {1, 2, 3, 4, 5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> scores(3);
    
    for (int i=0; i<answers.size(); i++)
    {
        if (answers[i] == student1[i%5]) 
            scores[0]++;
        if (answers[i] == student2[i%8]) 
            scores[1]++;
        if (answers[i] == student3[i%10]) 
            scores[2]++;
    }
    
    int max = *max_element(scores.begin(), scores.end());
    for (int i=0; i<3; i++)
        if (scores[i] == max)
            answer.push_back(i+1);
    
    return answer;
}