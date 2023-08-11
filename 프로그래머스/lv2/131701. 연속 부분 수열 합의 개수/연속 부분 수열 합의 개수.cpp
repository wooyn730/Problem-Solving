#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> sums;
    for (int i=1; i<=elements.size(); i++) // 길이 1~size
    {
        for (int j=0; j<elements.size(); j++) // 인덱스 0~size-1
        {
            // j부터 i개만큼 더하기
            int sum = 0;
            for (int k=0; k<i; k++)
                sum += elements[(j+k)%elements.size()];
            
            sums.insert(sum);
        }
    }
    return sums.size();
}