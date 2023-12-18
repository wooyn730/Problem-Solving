#include <string>
#include <iostream>
using namespace std;

long long solution(string numbers) {
    string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i=0; i<=9; i++)
    {
        while (true)
        {
            if (numbers.find(nums[i]) >= numbers.length())
                break;
            numbers.replace(numbers.find(nums[i]), nums[i].length(), to_string(i));
        }
    }
    return stoll(numbers);
}