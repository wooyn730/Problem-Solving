#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    // 숫자 해독 => 지도1, 2 만들기
    vector<string> answer;
    vector<string> str1;
    vector<string> str2;

    for (int i = 0; i < n; i++)
    {
        // 지도 1
        str1.push_back("");
        while (arr1[i] > 0)
        {
            if (arr1[i] % 2 == 0)
                str1[i] = '0' + str1[i];
            else
                str1[i] = '1' + str1[i];
            arr1[i] /= 2;
        }
        while (str1[i].length() != n)
        {
            str1[i] = '0' + str1[i];
        }

        // 지도 2
        str2.push_back("");
        while (arr2[i] > 0)
        {
            if (arr2[i] % 2 == 0)
                str2[i] = '0' + str2[i];
            else
                str2[i] = '1' + str2[i];
            arr2[i] /= 2;
        }
        while (str2[i].length() != n)
        {
            str2[i] = '0' + str2[i];
        }
    }

    // 지도1, 2 비교 => 비밀지도 만들기
    for (int i = 0; i < n; i++)
    {
        answer.push_back("");

        for (int j = 0; j < n; j++)
        {
            if (str1[i][j] == '0' && str2[i][j] == '0')
                answer[i] += ' ';
            else
                answer[i] += '#';
        }
    }

    return answer;
}