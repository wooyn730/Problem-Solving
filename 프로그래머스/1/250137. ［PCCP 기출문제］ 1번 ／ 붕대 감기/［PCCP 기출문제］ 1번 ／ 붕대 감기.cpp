#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health;
    int turn = 0;
    int combo = 0;
    int curAtk = 0;
    
    while (true)
    {
        if (turn == attacks[curAtk][0])
        {
            combo = 0;
            hp -= attacks[curAtk][1];
            curAtk++;
        }
        else
        {
            combo++;
            hp += bandage[1];
            
            if (combo == bandage[0])
            {
                hp += bandage[2];
                combo = 0;
            }
            
            
            if (hp > health)
                hp = health;
        }
        turn++;
        
        if (hp <= 0)
            return -1;
        
        if (curAtk == attacks.size())
            break;
    }
    
    return hp;
}