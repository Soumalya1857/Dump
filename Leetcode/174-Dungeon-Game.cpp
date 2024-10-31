// VERDICT: TLE

struct State{
    int x,y,health;

    State(int x, int y, int health){
        this->x = x;
        this->y = y;
        this->health = health;
    }
};
class Solution {
private:
    bool isValid(int row, int col, int x, int y){
        return x>=0 && x<row && y>=0 && y<col;
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int row = dungeon.size(), col = dungeon[0].size();

        int endPower = dungeon[row-1][col-1] < 0 ? -dungeon[row-1][col-1] : 0;

        State start(row-1,col-1, endPower);

        stack<State> s;
        s.push(start);

        int minHealth = INT_MAX;

        int dx[2] = {-1,0};
        int dy[2] = {0,-1};


        while(!s.empty()){
            State curr = s.top(); s.pop();

            if(curr.health < 0) continue;

            if(curr.x == 0 && curr.y == 0){
                minHealth = min(minHealth, curr.health);
                continue;
            }

            for(int i=0; i<2; i++){
                int newX = curr.x + dx[i];
                int newY = curr.y + dy[i];

                if(isValid(row, col, newX, newY)){

                   // if(dungeon[newX][newY] > 0){
                        int health = max(0, curr.health-dungeon[newX][newY]);
                        s.push(State(newX,newY, health));
                    //}
                    //s.push(State(newX, newY, curr.health + dungeon[newX][newY]));
                }
            }

        }

        return minHealth+1;
    }
};
// normal memo is not working for some reason
// don't know why but lets see

// https://leetcode.com/problems/dungeon-game/description/

// https://leetcode.com/problems/dungeon-game/solutions/745340/post-dedicated-to-beginners-of-dp-or-have-no-clue-how-to-start/
//https://leetcode.com/problems/dungeon-game/solutions/3055960/handwritten-step-by-step-in-detail-dry-run-fully-commented-recursive-approach/
