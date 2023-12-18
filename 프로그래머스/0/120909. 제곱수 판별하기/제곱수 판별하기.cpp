#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    float sq = sqrt(n);
    return (sq*sq == n ? 1 : 2);
}