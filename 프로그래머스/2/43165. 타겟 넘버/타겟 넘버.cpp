#include <string>
#include <vector>

using namespace std;

vector<int> _numbers;
int _target;
int answer;

void DFS(int num, int cnt)
{
    if (cnt == _numbers.size() - 1)
    {
        if (num == _target)
            answer++;
    }
    else
    {
        DFS(num + _numbers[cnt+1], cnt+1);
        DFS(num - _numbers[cnt+1], cnt+1);
    }
}

int solution(vector<int> numbers, int target) {
    _numbers = numbers;
    _target = target;
    
    DFS(numbers[0], 0);
    DFS(-numbers[0], 0);
    
    return answer;
}