#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftThumb = 10;
    int rightThumb = 12;
    
    for (int i=0; i<numbers.size(); i++)
    {
        switch(numbers[i])
        {
            case 1:
            case 4:
            case 7:
                leftThumb = numbers[i];
                answer += 'L';
                break;
            case 3:
            case 6:
            case 9:
                rightThumb = numbers[i];
                answer += 'R';
                break;
            case 2:
            case 5:
            case 8:
            case 0:
                if (numbers[i] == 0)
                    numbers[i] = 11;
                // 왼손과의 거리 계산
                int leftDis = abs(leftThumb - numbers[i]);
                int leftCnt = 0;
                while (leftDis>0)
                {
                    if (leftDis >= 3)
                    {
                        leftDis -= 3;
                        leftCnt++;
                    }
                    else
                    {
                        leftDis--;
                        leftCnt++;
                    }
                }
                // 오른손과의 거리 계산
                int rightDis = abs(rightThumb - numbers[i]);
                int rightCnt = 0;
                while (rightDis>0)
                {
                    if (rightDis >= 3)
                    {
                        rightDis -= 3;
                        rightCnt++;
                    }
                    else
                    {
                        rightDis--;
                        rightCnt++;
                    }
                }
                
                if (leftCnt == rightCnt)
                {
                    if (hand == "left")
                    {
                        answer += 'L';
                        leftThumb = numbers[i];
                    }
                    else
                    {
                        answer += 'R';
                        rightThumb = numbers[i];
                    }
                }
                else
                {
                    if (leftCnt < rightCnt)
                    {
                        answer += 'L';
                        leftThumb = numbers[i];
                    }
                    else
                    {
                        answer += 'R';
                        rightThumb = numbers[i];
                    }
                }
                break;
        }
    }
    
    return answer;
}