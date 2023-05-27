#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> doll;
    
    for (int i=0; i<moves.size(); i++)
    {
        for (int j=0; j<board[0].size(); j++)
        {
            if (board[j][moves[i]-1] != 0)
            {
                doll.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if (doll[doll.size()-1] == doll[doll.size()-2])
        {
            answer+=2;
            doll.pop_back();
            doll.pop_back();
        }
            
    }
    
    return answer;
    /*
    00000
    00103
    02501
    42442
    35131
    */
}