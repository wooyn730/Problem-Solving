#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string &a, string &b)
{
    return a < b;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);

    for (int i=0; i<phone_book.size()-1; i++)
    {
        for (int j=i+1; j<phone_book.size(); j++)
        {
            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length()))
                return false;
            else
                break;
        }
    }
    return true;
}